#pragma once

#include <list>
#include "ICmdHandler.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

struct CCmd
{
	CCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
		: sName(asName), sDesc(asDesc), fnCallback(afnCallback){}
	
	const char *sName{""};
	const char *sDesc{""};
	
	pfnCmdCallback fnCallback{nullptr};
};

using tCmdList = std::list<CCmd*>;

class CDefaultCmdHandler final : public ICmdHandler
{
public:
	CDefaultCmdHandler(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CDefaultCmdHandler() = default;
	
	void HandleCmd(const char *asCmd) override;
	
	void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc) override;
private:
	tCmdList mlstCmds;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz