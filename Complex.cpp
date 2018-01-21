#include "Complex.h"

Complex::Complex()
{
  R = I = 0.0;
}

Complex::Complex(double R, double I)
{this->R = R; this->I = I;}

Complex::Complex(Complex& C)
{
  copy(C);
}

void Complex::copy(Complex& C)
{
  R = C.R; I = C.I;
}

string Complex::getString()
{
  char text[100];
  if(I==0)sprintf(text, "%g", R);
  else if(R==0)sprintf(text, "%g * i", I);
  else if(I>0)sprintf(text, "%g + %g * i", R, I);
  else if(I<0)sprintf(text, "%g - %g * i", R, -I);
  return string(text);
}

double Complex::magnitude()
{
  return sqrt(R*R+I*I);
}
double Complex::angle()
{
  return atan2(I, R);
}
void Complex::negative()
{
  R*=-1; I*=-1;
}
double Complex::real()
{
  return R;
}
double Complex::imaginary()
{
  return I;
}

Complex Complex::addComplex(Complex& A, Complex& B)
{
  Complex C;
  C.R = A.R + B.R;
  C.I = A.I + B.I;
  return C;
}

void Complex::add(Complex& C)
{
  R += C.R;
  I += C.I;
}

void Complex::add(double D)
{
    R+=D;
}

void Complex::multiply(Complex& C)
{
    R=R*(C.R) - I*(C.I);
    I=R*(C.I) + I*(C.R);
}

void Complex::multiply(double D)
{
    R*=D;
    I*=D;
}


/*-----------OPERATORS-----------*/
Complex Complex::operator=(Complex& C)
{
  copy(C);
  return *this;
}
Complex Complex::operator=(double D)
{
  R = D;
  I = 0;
  return *this;
}
void Complex::operator+=(Complex& C)
{
  add(C);
}
void Complex::operator+=(double D)
{
  R += D;
}
Complex Complex::operator+(Complex& C)
{
    Complex Result;
    Result(*this);
    Result.add(C);
    return Result;
}
Complex Complex::operator+(double D)
{
    Complex Result;
    Result(*this);
    Result.add(D);
    return Result;
}

Complex Complex::operator-()
{
    R=-R;
    I=-I;
  return *this;
}
Complex::operator const string()
{
  return getString();
}
istream& operator >> (istream& is, Complex& C)
{
  is>>C.R;
  is>>C.I;
  return is;
}
ostream& operator << (ostream& os, Complex& C)
{
  os<<C.getString();
  return os;
}

Complex Complex::operator++()
{
  R++;
  return *this;
}
Complex Complex::operator++(int)
{
  Complex C = *this;
  R+=1;
  return C;
}
double Complex::operator[](string name)
{
  if(name=="magnitude")
    return magnitude();
  if(name=="angle")
    return angle();
  if(name=="real")
    return real();
  if(name=="imaginary")
    return imaginary();
  return 0.0;
}
double Complex::operator()(string name, string info)
{
  if(name=="angle")
  {
    if(info=="degree")
      return angle()*180.0/PI;
      if(info=="radian" || info.length()==0)
      return angle();
  }
  return (*this)[name];
}


Complex Complex::operator*(Complex& C)
{
    Complex Product;
    Product(*this);
    Product.multiply(C);
    return Product;
}
