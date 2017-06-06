#include "LogFile.hpp"

namespace rz
{

CLogFile::CLogFile(const tString &asName) : msName(asName), mpHandle(std::fopen(msName.c_str(), "a+"))
{
	if(!mpHandle)
		throw std::runtime_error("Cannot open the file %s", msName.c_str());
};

void CLogFile::Write(const tString &asMsg, ...)
{
	assert(mpHandle);
	
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg, lstArgs);
	va_end(lstArgs);
	
	fputs(sMsg, mpHandle);
	fflush(mpHandle);
};

void CLogFile::Close()
{
	assert(mpHandle);
	
	fputs("Closing the log file...", mpHandle);
	fflush(mpHandle);
	
	fclose(mpHandle);
};

}; // namespace rz