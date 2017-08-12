#pragma once

#include "core/ILog.hpp"

namespace rz
{

struct TCoreEnv;
class CLogFile;

class CLog final : public ILog
{
public:
	CLog(); //= default;
	~CLog(); //= default;
	
	bool Init(TCoreEnv &aCoreEnv);
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
	//ILogWriter *mpWriter{nullptr}; // to be able to change the output target (file or something else)
	std::unique_ptr<CLogFile> mpFile;
};

}; // namespace rz