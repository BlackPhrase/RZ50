#pragma once

namespace rz
{

struct INetAdr
{
	virtual bool IsLocal() const = 0;
};

}; // namespace rz