#pragma once

namespace rz
{

struct IConsole
{
	virtual void Printf(const char *asMsg, ...) = 0;
	
	//virtual void Warning(const char *asMsg, ...) = 0;
	//virtual void Error(const char *asMsg, ...) = 0;
};

}; // namespace rz