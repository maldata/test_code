#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "complex.h"

class ComplexFixture : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( ComplexFixture );
  
  CPPUNIT_TEST( testEquality );
  CPPUNIT_TEST( testAddition );
  CPPUNIT_TEST( testSubtraction );
  CPPUNIT_TEST( testMultiplication );
  CPPUNIT_TEST( testConjugate );
  CPPUNIT_TEST( testDivisionByDouble );
  CPPUNIT_TEST( testDivision );
  
  //  CPPUNIT_TEST_EXCEPTION( testDivideByZeroThrows, MathException );

  CPPUNIT_TEST_SUITE_END();
  
 private:
  Complex* m_10_1;
  Complex* m_1_1;
  Complex* m_11_2;
  Complex* m_1_4;
  Complex* m_5_1;
  Complex* m_1_21;
  Complex* m_11_n2;
  Complex* m_22_4;
  Complex* m_3_2;
  Complex* m_4_n3;
  Complex* m_625_1725;

 public:
  ComplexFixture();
  virtual ~ComplexFixture();
  
  void setUp();
  void tearDown();
  
  void testEquality();
  void testAddition();
  void testSubtraction();
  void testMultiplication();
  void testConjugate();
  void testDivisionByDouble();
  void testDivision();
  void testDivideByZeroThrows();
};
