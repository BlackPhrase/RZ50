#pragma once

namespace rz
{

class CUnknown
{
public:
	CUnknown() = default;
	~CUnknown() = default;
	
	void Info(const char *asMsg, ...);
	void Debug(const char *asMsg, ...);
	void Warning(const char *asMsg, ...);
	void Error(const char *asMsg, ...);
	void Fatal(const char *asMsg, ...);
private:
};

}; // namespace rz