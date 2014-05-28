//============================================================================
// Name        : MemoryAllocator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Complex.h"

int main_tt() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Complex* array[1000];
	for(int ii = 0; ii < 10000; ++ii)
	{
		for(int jj = 0; jj < 1000; ++jj)
		{
			array[jj]= new Complex(ii,jj);
		}
		for(int jj = 0; jj < 1000; ++jj)
		{
			delete array[jj];
		}
	}
	return 0;
}

