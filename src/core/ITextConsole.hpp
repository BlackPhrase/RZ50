#pragma once

namespace rz
{

struct ITextConsole
{
	///
	virtual bool Init() = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void Printf(const char *asMsg, ...) = 0;
	
	///
	virtual void Warning(const char *asMsg, ...) = 0;
	
	///
	virtual void Error(const char *asMsg, ...) = 0;
};

}; // namespace rz