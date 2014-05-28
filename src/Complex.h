/*
 * Complex.h
 *
 *  Created on: 12 mar 2014
 *      Author: piotr
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <stddef.h>
#include "MemoryManager.h"

class Complex {
public:
	//Complex();
	Complex(double a, double b);
	virtual ~Complex();

	/*inline void* operator new(size_t size);
	inline void* operator new[](size_t size);

	inline void operator delete(void* pointertoDelete);
	inline void operator delete[](void* arrayTodelete);*/

private:
	double r; //real part
	double c; //complex part

};

/*void* Complex::operator new(size_t size)
{
	return gMemoryManager.allocate(size);
}

void Complex::operator delete(void* pointerToDelete)
{
	gMemoryManager.free(pointerToDelete);
}*/

#endif /* COMPLEX_H_ */
