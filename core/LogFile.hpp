#pragma once

namespace rz
{

// TODO: inherit it from the CFile
class CLogFile final
{
public:
	CLogFile() = default;
	CLogFile(const tString &asName);
	
	~CLogFile(){Close();}
	
	//bool Open(const tString &asName);
	
	void Write(const tString &asMsg, ...);
	
	const tString &GetName() const {return msName;}
private:
	void Close();
	
	tString msName{""};
	
	FILE *mpHandle{nullptr};
};

}; // namespace rz