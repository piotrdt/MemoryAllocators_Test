/*
 * MemoryManager.cpp
 *
 *  Created on: 12 mar 2014
 *      Author: piotr
 */

#include "MemoryManager.h"
#include "Complex.h"
#include <stdlib.h>

#define POOLSIZE 32

MemoryManager gMemoryManager;

MemoryManager::MemoryManager ()
{
	freeStoreHead = NULL;
	expandPoolSize();
}

MemoryManager::~MemoryManager ()
{
	cleanUp();
}

void* MemoryManager::allocate(size_t size)
{
	if(freeStoreHead == 0)
		expandPoolSize();

	FreeStore* head = freeStoreHead;
	freeStoreHead = head->next;
	return head;
}

void MemoryManager::free(void* deleted)
{
	FreeStore* head = static_cast<FreeStore*>(deleted);
	head->next = freeStoreHead;
	freeStoreHead = head;
}

void MemoryManager::expandPoolSize()
{
	size_t size = (sizeof(Complex)>sizeof(FreeStore) ? sizeof(Complex) : sizeof(FreeStore));

	FreeStore* head = reinterpret_cast<FreeStore*>(new char[size]);
	freeStoreHead = head;

	for(int idx = 0; idx < POOLSIZE; ++idx)
	{
		head->next = reinterpret_cast<FreeStore*>(new char[size]);
		head = head->next;
	}
	head->next = NULL;
}

void MemoryManager::cleanUp()
{
	FreeStore* nextPtr = freeStoreHead;
	for(; nextPtr != NULL; nextPtr = freeStoreHead)
	{
		freeStoreHead = freeStoreHead->next;
		delete[] nextPtr;
	}
}

