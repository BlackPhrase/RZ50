#pragma once

#include <memory>
#include <list>
#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct TCoreEnv;
class CCore;

class CCmdBuffer;
class CCmdExecutor;

struct CCmd
{
	CCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
		: sName(asName), sDesc(asDesc), fnCallback(afnCallback){}
	
	const char *sName{""};
	const char *sDesc{""};
	
	pfnCmdCallback fnCallback{nullptr};
};

using tCmdList = std::list<CCmd*>;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore);
	~CCmdProcessor();
	
	void Init(TCoreEnv &aCoreEnv);
	
	void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc) override;
	
	void BufferText(const char *asText, InsertMode aeMode) override;
	void ExecText(const char *asText) override;
	
	void ExecBuffer() override;
private:
	tCmdList mlstCmds;
	
	std::unique_ptr<CCmdBuffer> mpBuffer;
	std::unique_ptr<CCmdExecutor> mpExecutor;
	
	const TCoreEnv &mCoreEnv;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz