#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "complexfixture.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ComplexFixture );

// http://cppunit.sourceforge.net/doc/cvs/cppunit_cookbook.html
// https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
// http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
// http://www.mesacc.edu/~scotz47781/mat120/notes/complex/dividing/dividing_complex.html

int main()
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  runner.run();
  
  return 0;
}
