#pragma once

#include "ICmdHandler.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CDefaultCmdHandler final : public ICmdHandler
{
public:
	CDefaultCmdHandler(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CDefaultCmdHandler() = default;
	
	bool HandleCmd(const char *asCmd) override;
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz