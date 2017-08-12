#pragma once

namespace rz
{

struct ICmdHandler
{
	virtual bool HandleCmd(const char *asText) = 0;
};

}; // namespace rz