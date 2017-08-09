#pragma once

#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct TCoreEnv;
class CCore;

class CCmdBuffer;
class CCmdExecutor;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore) : mCoreEnv(aCoreEnv), mpCore(apCore){Init();} //= default;
	~CCmdProcessor() = default;
	
	void Init(TCoreEnv &aCoreEnv);
	
	void BufferText(const char *asText, InsertMode aeMode) override;
	void ExecText(const char *asText) override;
	
	void ExecBuffer() override;
private:
	CCmdBuffer *mpBuffer{nullptr};
	CCmdExecutor *mpExecutor{nullptr};
	
	const TCoreEnv &mCoreEnv;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz