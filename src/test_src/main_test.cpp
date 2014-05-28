
#include <iostream>
using namespace std;

#include "BitMapEntryTest.h"
#include <cppunit/ui/text/TestRunner.h>

/*extern "C" int main()
{
	std::cout << "!!!Hello World from MAIN TEST!!!" << std::endl; // prints !!!Hello World!!!
sad	BitMapEntry_Test testObject;

	if(testObject.Test_Construct() == false)
		cout << "test of the construction of BitMapEntry object failed!" << std::endl;
	else
		cout << "test of the construction of BitMapEntry object passed!" << std::endl;

	return 0;
}*/

//____________________________________________________________________________//

int main( int argc, char* argv[] )
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
	runner.run();

	return 0;
}

//____________________________________________________________________________//
