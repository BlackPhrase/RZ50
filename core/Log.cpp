#include "Log.hpp"
#include "LogFile.hpp"

namespace rz
{

void CLog::Write(const char *asMsg)
{
	mpFile->Write(asMsg);
};

void CLog::Info(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	sprintf(sMsg, "[INFO] %s", sMsg);
	Write(sMsg);
};

void CLog::Debug(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	sprintf(sMsg, "[DEBUG] %s", sMsg);
	Write(sMsg);
};

void CLog::Warning(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	sprintf(sMsg, "[WARNING] %s", sMsg);
	Write(sMsg);
};

void CLog::Error(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	sprintf(sMsg, "[ERROR] %s", sMsg);
	Write(sMsg);
};

void CLog::FatalError(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	sprintf(sMsg, "[FATAL] %s", sMsg);
	Write(sMsg);
};

void CLog::TraceInit(const char *asMsg)
{
	char sMsg[256] = {};
	
	sprintf(sMsg, "Initializing the %s...", asMsg);
	Write(sMsg);
};

void CLog::TraceShutdown(const char *asMsg)
{
	char sMsg[256] = {};
	
	sprintf(sMsg, "Shutting down the %s...", asMsg);
	Write(sMsg);
};

}; // namespace rz