/*
 * BitMapEntry.cpp
 *
 *  Created on: 16 mar 2014
 *      Author: piotr
 */

#include "BitMapEntry.h"
#include <stddef.h>
#include <string.h>

#define UINT_SIZE_IN_BITS (8*sizeof(unsigned int))//8 bits * number of bytes on given architecture and compiler
#define UINT_SIZE_IN_BYTES (sizeof(unsigned int))

BitMapEntry::BitMapEntry (unsigned int MemoryBlockIndex, unsigned int BlockItemCount, unsigned int AllocItemSize)
	: Index(MemoryBlockIndex), BitMapSize(BlockItemCount), AllocationSize(AllocItemSize)
{
	BlockAvailable = BlockItemCount * UINT_SIZE_IN_BITS;
	BitMap = new unsigned int[BlockAvailable];
	if(BitMap != NULL)
		memset(BitMap,0xff,BitMapSize * sizeof(int));
}

BitMapEntry::~BitMapEntry ()
{
	if(BitMap != NULL)
		delete[] BitMap;
}

void BitMapEntry::SetBit(bool flag, int position) throw()
{
	//evaluate index position in the BitMap table
	unsigned int bitMapIdx = position / UINT_SIZE_IN_BITS;
	//evaluate bit position in the particular BitMap entry
	unsigned int bitNo = position % UINT_SIZE_IN_BITS;
	//update number of available entries in the memory block
	BlockAvailable += (flag == true) ? 1 : -1;

	if(bitMapIdx > BitMapSize)
		throw "error, attempt to set BitMap entry, which does'n exist";

	if(flag == true)
		BitMap[bitMapIdx] = BitMap[bitMapIdx] | (0x1 << bitNo);
	else
		BitMap[bitMapIdx] = BitMap[bitMapIdx] & ~(0x1 << bitNo);
}

void BitMapEntry::SetBits(bool flag, int position, unsigned int Count /* = 1*/) throw()
{
	//evaluate index position in the BitMap table
	unsigned int bitMapIdx = position / UINT_SIZE_IN_BITS;
	//evaluate bit position in the particular BitMap entry
	unsigned int bitNo = position % UINT_SIZE_IN_BITS;
	//update number of available entries in the memory block
	BlockAvailable += (flag == true) ? 1 : -1;

	if(bitMapIdx > BitMapSize)
		throw "error, attempt to set BitMap entry, which does'n exist";

	int bitsToUpdate = 0;
	if(Count < UINT_SIZE_IN_BITS - bitNo)
	{
		bitsToUpdate = Count;
		Count = 0;
	}
	else
	{
		bitsToUpdate = UINT_SIZE_IN_BITS - bitNo;
		Count = UINT_SIZE_IN_BITS - bitNo;
	}
	SetMultipleBits(flag, bitMapIdx, bitNo, bitsToUpdate);

	while(Count > 0)
	{
		//update variables
		bitMapIdx++;
		bitNo = 0;
		if(Count < UINT_SIZE_IN_BITS)
		{
			bitsToUpdate = Count;
			Count = 0;
		}
		else
		{
			Count -= UINT_SIZE_IN_BITS;
			bitsToUpdate = UINT_SIZE_IN_BITS;
		}
		SetMultipleBits(flag, bitMapIdx, bitNo, bitsToUpdate);
	};
}

void BitMapEntry::SetMultipleBits(bool flag,
                                  unsigned int BitMapIdx,
                                  unsigned int StartBitNo,
                                  unsigned int Count /* = 1*/) throw()
{
	if (Count > UINT_SIZE_IN_BITS - StartBitNo)
		throw "error, attempt to set too many bits";
	if(BitMapIdx > BitMapSize)
		throw "error, attempt to set BitMap entry, which does'n exist";

	unsigned int mask;
	if(Count > 1) //create pattern to update
	{
		mask = (0xFFFFFFFF << StartBitNo) & (0xFFFFFFFF >> (UINT_SIZE_IN_BITS - (StartBitNo + Count)));
	}
	else
		mask = 0x1;

	if(flag == true)
		BitMap[BitMapIdx] = BitMap[BitMapIdx] | mask;
	else
		BitMap[BitMapIdx] = BitMap[BitMapIdx] & ~mask;
}

void* BitMapEntry::FirsFreeBlock(size_t size)
{
	return NULL;
}
void* BitMapEntry::ComplexObjectAdress(int pos)
{
	return NULL;
}
void* BitMapEntry::Head()
{
	return NULL;
}
