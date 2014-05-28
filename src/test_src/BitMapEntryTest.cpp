/*
 * BitMapEntryTest.cpp
 *
 *  Created on: 17 mar 2014
 *      Author: piotr
 */

#include "BitMapEntryTest.h"
#include "../BitMapEntry.h"
#include <stddef.h>

#ifdef __TESTS_COMPILATION_ENABLED__

CPPUNIT_TEST_SUITE_REGISTRATION(BitMapEntry_Test);

#define UINT_SIZE_IN_BITS (8*sizeof(unsigned int))//8 bits * number of bytes on given architecture and compiler
#define UINT_SIZE_IN_BYTES (sizeof(unsigned int))

BitMapEntry_Test::BitMapEntry_Test ()
{


}

BitMapEntry_Test::~BitMapEntry_Test ()
{
	// TODO Auto-generated destructor stub
}

struct TestAllocationStruct
{
	int a;
	int b;
	int c;
};

void BitMapEntry_Test::setUp()
{
	//create bitmap entry for test purposes.
	m_ItemCounts__ = 10;
	m_EmptyBitMapEntry__ = new BitMapEntry(0, 10, sizeof(TestAllocationStruct));
}

void BitMapEntry_Test::tearDown()
{
	delete m_EmptyBitMapEntry__;
}

void BitMapEntry_Test::Test_Construct(void)
{
	BitMapEntry test_instance(123,10,sizeof(TestAllocationStruct));

	CPPUNIT_ASSERT(test_instance.Index == 123);
	CPPUNIT_ASSERT(test_instance.BitMapSize == 10);
	CPPUNIT_ASSERT(test_instance.AllocationSize == sizeof(TestAllocationStruct));
	CPPUNIT_ASSERT(test_instance.BitMap != NULL);
	CPPUNIT_ASSERT(test_instance.BlockAvailable == 10 * 8 * sizeof(unsigned int));

}

void BitMapEntry_Test::Test_SetSingleBit(void)
{
	unsigned int bitToSet = 42;
	unsigned int mapIdx = 42 / UINT_SIZE_IN_BITS;
	unsigned int mapItem = 42 % UINT_SIZE_IN_BITS;

	m_EmptyBitMapEntry__->SetBit(false,bitToSet);

	CPPUNIT_ASSERT((m_EmptyBitMapEntry__->BitMap[mapIdx] & (0x1 << mapItem)) == 0x0);
	return;
}


void BitMapEntry_Test::Test_SetASetOfSingleBits(void)
{
	const unsigned int numberOfBitsToSet = 15;

	unsigned int bitToSet[numberOfBitsToSet];
	unsigned int mapIdx[numberOfBitsToSet];
	unsigned int mapBit[numberOfBitsToSet];

	for (unsigned int idx = 0; idx < numberOfBitsToSet; ++idx)
	{
		bitToSet[idx] = (0 + idx * 2);
		mapIdx[idx] = bitToSet[idx] / UINT_SIZE_IN_BITS;
		mapBit[idx] = bitToSet[idx] % UINT_SIZE_IN_BITS;
	}

	for(unsigned int idx = 0; idx < numberOfBitsToSet; ++idx)
	{
		m_EmptyBitMapEntry__->SetBit(false, bitToSet[idx]);
	}

	CPPUNIT_ASSERT(m_EmptyBitMapEntry__->BlockAvailable == ((m_ItemCounts__ * UINT_SIZE_IN_BITS) - numberOfBitsToSet));

	for(unsigned int idx = 0; idx < numberOfBitsToSet; ++idx)
	{
		CPPUNIT_ASSERT((m_EmptyBitMapEntry__->BitMap[mapIdx[idx]] & (0x1 << mapBit[idx])) == 0x0);
	}

}

void BitMapEntry_Test::Test_SetAllBitsInOneMapEntryAsSingleOp(void)
{
	unsigned int itemToClear = 4;
	unsigned int offsetOfItem = 4 * UINT_SIZE_IN_BITS;
	//clear all 32-bits

	for(unsigned int idx = 0; idx < UINT_SIZE_IN_BITS; ++idx)
	{
		m_EmptyBitMapEntry__->SetBit(false, offsetOfItem + idx);
	}

	CPPUNIT_ASSERT(m_EmptyBitMapEntry__->BlockAvailable == (m_ItemCounts__ * UINT_SIZE_IN_BITS - UINT_SIZE_IN_BITS));
	CPPUNIT_ASSERT(m_EmptyBitMapEntry__->BitMap[itemToClear] == 0x0);

}

void BitMapEntry_Test::Test_SetBitAfterTheBitMapEnd(void)
{
	unsigned int bitToSet = m_ItemCounts__ * UINT_SIZE_IN_BITS + 10;
	unsigned int mapIdx = 42 / UINT_SIZE_IN_BITS;
	unsigned int mapItem = 42 % UINT_SIZE_IN_BITS;

	m_EmptyBitMapEntry__->SetBit(false,bitToSet);

	CPPUNIT_ASSERT((m_EmptyBitMapEntry__->BitMap[mapIdx] & (0x1 << mapItem)) == 0x0);
	return;
}
#endif //__TESTS_COMPILATION_ENABLED__
