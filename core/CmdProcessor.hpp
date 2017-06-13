#pragma once

#include "core/ICmdProcessor.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct TCoreEnv;
class CCore;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore) : mCoreEnv(aCoreEnv), mpCore(apCore){} //= default;
	~CCmdProcessor() = default;
	
	void Insert(const char *asCmd) override;
	
	void Append(const char *asCmd) override;
	
	void ExecText(const char *asText) override;
	
	void Exec() override;
private:
	const TCoreEnv &mCoreEnv;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz