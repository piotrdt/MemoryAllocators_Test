/*
 * BitMapEntryTest.h
 *
 *  Created on: 17 mar 2014
 *      Author: piotr
 */

#ifndef BITMAPENTRYTEST_H_
#define BITMAPENTRYTEST_H_

#ifdef __TESTS_COMPILATION_ENABLED__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../BitMapEntry.h"

//this class is used to test BitMapEntry class functionalities
class BitMapEntry_Test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(BitMapEntry_Test);
		CPPUNIT_TEST(Test_Construct);
		CPPUNIT_TEST(Test_SetSingleBit);
		CPPUNIT_TEST(Test_SetASetOfSingleBits);
		CPPUNIT_TEST(Test_SetAllBitsInOneMapEntryAsSingleOp);
		CPPUNIT_TEST(Test_SetBitAfterTheBitMapEnd);
	CPPUNIT_TEST_SUITE_END();

public:
	BitMapEntry_Test ();
	virtual
	~BitMapEntry_Test ();

	virtual void setUp();
	virtual void tearDown();

	void Test_Construct(void);
	void Test_SetSingleBit(void);
	void Test_SetASetOfSingleBits(void);
	void Test_SetAllBitsInOneMapEntryAsSingleOp(void);
	void Test_SetBitAfterTheBitMapEnd(void);

private:
	unsigned int m_ItemCounts__;
	BitMapEntry* m_EmptyBitMapEntry__;
};

#endif //__TESTS_COMPILATION_ENABLED__

#endif /* BITMAPENTRYTEST_H_ */
