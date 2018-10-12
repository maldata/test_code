class Complex
{
  //friend bool operator == (const Complex& a, const Complex& b);
  
  double real;
  double imaginary;
  
 public:
  Complex(double r, double i = 0);
  Complex(const Complex &c2);
  virtual ~Complex();
  
  bool operator == ( const Complex& comp );
  Complex operator + ( const Complex& other );
  Complex operator - ( const Complex& other );
  Complex operator * ( const Complex& other );
  Complex operator / ( const Complex& other );
  Complex operator / ( double denom );

  Complex conjugate() const;
};
