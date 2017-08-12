#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

// TODO: inherit it from the CFile
class CLogFile final
{
public:
	CLogFile() = default;
	CLogFile(const string &asName);
	
	~CLogFile(){Close();}
	
	//bool Open(const string &asName);
	
	void Write(const string &asMsg, ...);
	
	const string &GetName() const {return msName;}
private:
	void Close();
	
	string msName{""};
	
	FILE *mpHandle{nullptr};
};

}; // namespace rz