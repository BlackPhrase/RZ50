#pragma once

namespace rz
{

struct ILog
{
	///
	virtual void Write(const char *asMsg) = 0;
	
	///
	virtual void Info(const char *asMsg, ...) = 0;
	
	///
	virtual void Debug(const char *asMsg, ...) = 0;
	
	///
	virtual void Warning(const char *asMsg, ...) = 0;
	
	///
	virtual void Error(const char *asMsg, ...) = 0;
};

}; // namespace rz