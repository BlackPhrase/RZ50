#pragma once

#include <memory>
#include "core/TCoreEnv.hpp"
#include "core/ISubSystem.hpp"

namespace rz
{

class CNetworkModule final : public ISubSystem
{
public:
	CNetworkModule(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CNetworkModule() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Network";}
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz