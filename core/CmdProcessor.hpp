#pragma once

#include <deque>
#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct TCoreEnv;
class CCore;

using tCmdTextQue = std::deque<string>;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore) : mCoreEnv(aCoreEnv), mpCore(apCore){} //= default;
	~CCmdProcessor() = default;
	
	void Insert(const char *asCmd) override; // InsertText
	
	void Append(const char *asCmd) override; // AppendText
	
	void ExecText(const char *asText) override;
	
	void Exec() override; // ExecBuffer
private:
	tCmdTextQue mCmdBuffer;
	
	const TCoreEnv &mCoreEnv;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz