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
}

void ComplexFixture::tearDown() 
{
  delete m_10_1;
  delete m_1_1;
  delete m_11_2;
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

void ComplexFixture::testDivideByZeroThrows()
{
  // The following line should throw a MathException.
  *m_10_1 / Complex(0);
}
