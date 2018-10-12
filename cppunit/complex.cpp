#include "complex.h"

Complex::Complex(double r, double i) 
  : real(r), imaginary(i) 
{
}

// Copy constructor
Complex::Complex(const Complex &c2)
{
  real = c2.real;
  imaginary = c2.imaginary;
}

Complex::~Complex()
{
}

bool Complex::operator == (const Complex& comp)
{ 
  return real == comp.real && imaginary == comp.imaginary; 
}

Complex Complex::operator + (const Complex& other)
{
  return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator - (const Complex& other)
{
  return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator * (const Complex& other)
{
  double new_real = (real * other.real) - (imaginary * other.imaginary);
  double new_imag = (real * other.imaginary) + (other.real * imaginary);
  
  return Complex(new_real, new_imag);
}

Complex Complex::operator / (const Complex& other)
{
  Complex conj = other.conjugate();
  Complex numerator = (*this) * conj;

  double denom = (other.real * other.real) + (other.imaginary * other.imaginary);
  
  return numerator / denom;
}

Complex Complex::operator / ( double denom )
{
  return Complex(real/denom, imaginary/denom);
}

Complex Complex::conjugate() const
{
  return Complex(real, -imaginary);
}
