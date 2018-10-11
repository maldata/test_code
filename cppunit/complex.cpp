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
  return Complex(0, 0);
}

Complex Complex::operator / (const Complex& other)
{
  Complex conj = Complex(other.real, -other.imaginary);
  //  Complex result = (*this) * conj;
  return Complex(0,0);
}

Complex Complex::conjugate()
{
  return Complex(real, -imaginary);
}
