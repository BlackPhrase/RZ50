#pragma once

#include "IMemory.hpp"

class CMemory final : public IMemory
{
public:
	void *Alloc(size_t anSize) override;
	void Free(void *apData) override;
};