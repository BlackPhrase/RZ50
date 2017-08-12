#pragma once

#include "ICmdHandler.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CDefaultCmdHandler final : public ICmdHandler
{
public:
	CDefaultCmdHandler(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CDefaultCmdHandler() = default;
	
	bool HandleCmd(const char *asCmd) override;
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz