/*
 * BitMapEntry.h
 *
 *  Created on: 16 mar 2014
 *      Author: piotr
 */

#ifndef BITMAPENTRY_H_
#define BITMAPENTRY_H_

#include <stddef.h>
#ifdef c
#include "test_src/BitMapEntryTest.h"
#endif //__TEST_COMPILAION_ENABLED__

#define BIT_MAP_SIZE 1024

class BitMapEntry
{
public:
	BitMapEntry (unsigned int MemoryBlockIndex, unsigned int BilockItemCount, unsigned int AllocItemSize);
	virtual ~BitMapEntry ();

	void SetBits(bool flag, int position, unsigned int Count = 1) throw(); //sets multiple bits, even on BitMap entry borders
	void SetBit(bool flag, int position) throw();

	void* FirsFreeBlock(size_t size);
	void* ComplexObjectAdress(int pos);
	void* Head();

private:
	void SetMultipleBits(bool flag, unsigned int BitMapIdx, unsigned int StartBitNo, unsigned int Count = 1) throw();

	const unsigned int Index;				///<identifier of the memory block managed by particular BitMapEntry
	const unsigned int BitMapSize;			///<size of BitMap
	const unsigned int AllocationSize;		///<size of allocation block the BitMap description/state is holding in each bit
	unsigned int* BitMap;					///<table with information about available or not memory blocks in this memory allocation part
	unsigned int BlockAvailable;			///<number of available allocation entries in the managed memory block, number of bits in unsigned int variable * BlockItemCount passed during creation of the BitMapEntry

#ifdef __TESTS_COMPILATION_ENABLED__
	friend class BitMapEntry_Test;
#endif //__TEST_COMPILAION_ENABLED__
};

#endif /* BITMAPENTRY_H_ */
