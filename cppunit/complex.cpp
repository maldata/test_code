#include "complex.h"

Complex::Complex( double r, double i ) 
    : real(r), imaginary(i) 
  {
  }

bool Complex::operator == ( const Complex& comp )
{ 
  return real == comp.real && imaginary == comp.imaginary; 
}

Complex Complex::operator + ( const Complex& other )
{
  Complex result = Complex(real + other.real, imaginary + other.imaginary);
  return result;
}

Complex Complex::operator / ( const Complex& other )
{
  Complex conj = Complex(other.real, -other.imaginary);
  //  Complex result = (*this) * conj;
  return Complex(0,0);
}
