#include <memory>
#include "Log.hpp"
#include "LogFile.hpp"

namespace rz
{

CLog::CLog() = default;
CLog::~CLog() = default;

bool CLog::Init()
{
	mpFile = std::make_unique<CLogFile>("RZ"); // timestamp?
	
	//TraceInit("Log"); // by the fact that it does output to the log file it's initialized; no need for that...
	return true;
};

void CLog::Shutdown()
{
	//TraceShutdown("Log");
};

void CLog::Write(const char *asMsg)
{
	char sMsg[strlen(asMsg) + 1] = {};
	
	strcpy(sMsg, asMsg);
	strcat(sMsg, "\n");
	
	mpFile->Write(sMsg);
};

void CLog::Info(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	strcpy(sMsg, "[INFO] ");
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	Write(sMsg);
};

void CLog::Debug(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	strcpy(sMsg, "[DEBUG] ");
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	Write(sMsg);
};

void CLog::Warning(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	strcpy(sMsg, "[WARNING] ");
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	Write(sMsg);
};

void CLog::Error(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	strcpy(sMsg, "[ERROR] ");
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	Write(sMsg);
};

void CLog::FatalError(const char *asMsg, ...)
{
	char sMsg[256] = {};
	va_list lstArgs;
	
	strcpy(sMsg, "[FATAL] ");
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
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