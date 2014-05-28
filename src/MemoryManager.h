/*
 * MemoryManager.h
 *
 *  Created on: 12 mar 2014
 *      Author: piotr
 */

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include <stddef.h>

class IMemoryManager
{
public:
	virtual void* allocate(size_t size) = 0;
	virtual void free(void* deleted) = 0;
};

class MemoryManager : public IMemoryManager
{
	struct FreeStore
	{
		FreeStore *next;
	};

	void expandPoolSize();
	void cleanUp();
	FreeStore* freeStoreHead;

public:
	MemoryManager ();
	virtual	~MemoryManager ();

	virtual void* allocate(size_t size);
	virtual void free(void* deleted);
};

extern MemoryManager gMemoryManager;

#endif /* MEMORYMANAGER_H_ */
