#pragma once

#include "IMemory.hpp"

namespace rz
{

class CMemory final : public IMemory
{
public:
	void *Alloc(size_t anSize) override;
	void Free(void *apData) override;
};

}; // namespace rz