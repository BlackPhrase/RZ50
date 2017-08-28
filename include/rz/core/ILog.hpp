#pragma once

namespace rz
{

struct ILog
{
	/// Writes a message into the log
	virtual void Write(const char *asMsg) = 0;
	
	/// Writes a formatted message into the log with "INFO" prepended
	virtual void Info(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "DEBUG" prepended
	virtual void Debug(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "WARNING" prepended
	virtual void Warning(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "ERROR" prepended
	virtual void Error(const char *asMsg, ...) = 0;
	
	/// Writes a formatted message into the log with "FATAL" prepended
	virtual void FatalError(const char *asMsg, ...) = 0;
	
	///
	virtual void TraceInit(const char *asMsg) = 0;
	
	///
	virtual void TraceShutdown(const char *asMsg) = 0;
};

}; // namespace rz