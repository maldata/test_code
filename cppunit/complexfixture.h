#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "complex.h"

class ComplexFixture : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( ComplexFixture );
  
  CPPUNIT_TEST( testEquality );
  CPPUNIT_TEST( testAddition );
  //  CPPUNIT_TEST_EXCEPTION( testDivideByZeroThrows, MathException );

  CPPUNIT_TEST_SUITE_END();
  
 private:
  Complex *m_10_1;
  Complex *m_1_1;
  Complex *m_11_2;

 public:
  ComplexFixture();
  virtual ~ComplexFixture();
  
  void setUp();
  void tearDown();
  
  void testEquality();
  void testAddition();
  void testDivideByZeroThrows();
};
