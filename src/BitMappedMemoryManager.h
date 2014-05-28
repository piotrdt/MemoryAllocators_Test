/*
 * BitMappedMemoryManager.h
 *
 *  Created on: 12 mar 2014
 *      Author: piotr
 */

#ifndef BITMAPPEDMEMORYMANAGER_H_
#define BITMAPPEDMEMORYMANAGER_H_

#include <vector>
#include <set>
#include <map>

#include "MemoryManager.h"

typedef struct ArrayInfo
{
	int MemPoolListIndex;
	int StartPOsition;
	int Size;
} ArrayMemoryInfo;

class BitMappedMemoryManager : public IMemoryManager
{
public:
	BitMappedMemoryManager ();
	virtual	~BitMappedMemoryManager ();

	//void* allocate(size_t size);
	//void free(void* deleted);
	//std::vector<void*> GetMemoryPoolList();

private:
	//void* AllocateArray(size_t size);
	//void* AllocateChunkAndInitBitMap();
	//void SetBlockBit(void* object, bool flag);
	//void SetMultipleBlockBits(ArrayMemoryInfo* Info, bool flag);

	//members
	//std::vector<void*> MemoryPoolList;
	//std::vector<BitMapEntry> BitMapEntryList;
	//std::set<BitMapEntry*> FreeMapEntries;
	//std::map<void*, ArrayMemoryInfo> ArrayMemoryList;
};

#endif /* BITMAPPEDMEMORYMANAGER_H_ */
