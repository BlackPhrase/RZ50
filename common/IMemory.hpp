#pragma once

#include <cstring>

struct IMemory
{
	virtual void *Alloc(size_t anSize) = 0;
	virtual void Free(void *apData) = 0;
};