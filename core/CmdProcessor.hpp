#pragma once

#include <deque>
#include <list>
#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct TCoreEnv;
class CCore;

using tCmdTextQue = std::deque<string>;

struct ICmdHandler;
using tCmdHandlerList = std::list<ICmdHandler*>;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore) : mCoreEnv(aCoreEnv), mpCore(apCore){Init();} //= default;
	~CCmdProcessor() = default;
	
	//void AddCmdHandler(const ICmdHandler &aHandler) override;
	void Init(TCoreEnv &aCoreEnv);
	
	void Insert(const char *asCmd) override; // InsertText
	
	void Append(const char *asCmd) override; // AppendText
	
	void ExecText(const char *asText) override;
	
	void Exec() override; // ExecBuffer
private:
	tCmdTextQue mCmdBuffer;
	tCmdHandlerList mlstHandlers;
	
	const TCoreEnv &mCoreEnv;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz