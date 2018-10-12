#include "complexfixture.h"

ComplexFixture::ComplexFixture()
  : CppUnit::TestFixture()
{
}

ComplexFixture::~ComplexFixture()
{
}

void ComplexFixture::setUp()
{
  m_10_1 = new Complex( 10, 1 );
  m_1_1 = new Complex( 1, 1 );
  m_11_2 = new Complex( 11, 2 );
  m_1_4 = new Complex(1, 4);
  m_5_1 = new Complex(5, 1);
  m_1_21 = new Complex(1, 21);
  m_11_n2 = new Complex(11, -2);
  m_22_4 = new Complex(22, 4);
  m_3_2 = new Complex(3, 2);
  m_4_n3 = new Complex(4, -3);
  m_625_1725 = new Complex(6.0/25.0, 17.0/25.0);
}

void ComplexFixture::tearDown() 
{
  delete m_10_1;
  delete m_1_1;
  delete m_11_2;
  delete m_1_4;
  delete m_5_1;
  delete m_1_21;
  delete m_11_n2;
  delete m_22_4;
  delete m_3_2;
  delete m_4_n3;
  delete m_625_1725;
}

void ComplexFixture::testEquality()
{
  CPPUNIT_ASSERT( *m_10_1 == *m_10_1 );
  CPPUNIT_ASSERT( !(*m_10_1 == *m_11_2) );
}

void ComplexFixture::testAddition()
{
  CPPUNIT_ASSERT( *m_10_1 + *m_1_1 == *m_11_2 );
}

void ComplexFixture::testSubtraction()
{
  CPPUNIT_ASSERT( *m_11_2 - *m_1_1 == *m_10_1 );
}

void ComplexFixture::testMultiplication()
{
  CPPUNIT_ASSERT( *m_1_4 * *m_5_1 == *m_1_21 );
}

void ComplexFixture::testConjugate()
{
  CPPUNIT_ASSERT( m_11_2->conjugate() == *m_11_n2 );
}

void ComplexFixture::testDivisionByDouble()
{
  CPPUNIT_ASSERT( *m_22_4 / 2.0 == *m_11_2 );
}

void ComplexFixture::testDivision()
{
  CPPUNIT_ASSERT( *m_3_2 / *m_4_n3 == *m_625_1725 );
}

void ComplexFixture::testDivideByZeroThrows()
{
  // The following line should throw a MathException.
  *m_10_1 / Complex(0);
}
