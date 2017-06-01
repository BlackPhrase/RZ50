#pragma once

#include "ILog.hpp"

namespace rz
{

class CLog final : public ILog
{
public:
	CLog() = default;
	~CLog() = default;
	
	void Write(const char *asMsg) override;
	
	void Info(const char *asMsg, ...) override;
	void Debug(const char *asMsg, ...) override;
	void Warning(const char *asMsg, ...) override;
	void Error(const char *asMsg, ...) override;
	void FatalError(const char *asMsg, ...) override;
	
	void TraceInit(const char *asMsg) override;
	void TraceShutdown(const char *asMsg) override;
};

}; // namespace rz