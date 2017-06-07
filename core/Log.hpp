#pragma once

#include "core/ILog.hpp"

namespace rz
{

class CLogFile;

class CLog final : public ILog
{
public:
	CLog(); //= default;
	~CLog(); //= default;
	
	bool Init();
	void Shutdown();
	
	void Write(const char *asMsg) override;
	
	void Info(const char *asMsg, ...) override;
	void Debug(const char *asMsg, ...) override;
	void Warning(const char *asMsg, ...) override;
	void Error(const char *asMsg, ...) override;
	void FatalError(const char *asMsg, ...) override;
	
	void TraceInit(const char *asMsg) override;
	void TraceShutdown(const char *asMsg) override;
private:
	//ILogDirector *mpDirector{nullptr}; // to be able to change the receiever
	std::unique_ptr<CLogFile> mpFile;
};

}; // namespace rz