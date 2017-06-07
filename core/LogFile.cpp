#include "LogFile.hpp"

namespace rz
{

CLogFile::CLogFile(const string &asName) : msName(asName), mpHandle(std::fopen(msName.c_str(), "a+"))
{
	if(!mpHandle)
	{
		string sError{"Cannot open the file " + msName};
		throw std::runtime_error(sError);
	};
};

void CLogFile::Write(const string &asMsg, ...)
{
	assert(mpHandle);
	
	char sMsg[256] = {};
	va_list lstArgs;
	
	va_start(lstArgs, asMsg);
	vsprintf(sMsg, asMsg.c_str(), lstArgs);
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