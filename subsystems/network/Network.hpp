#pragma once

#include <memory>
#include "core/ISubSystem.hpp"
#include "core/TCoreEnv.hpp"
#include "network/INetwork.hpp"

namespace rz
{

class CNetwork final : public ISubSystem, INetwork
{
public:
	CNetwork(const TCoreEnv &aCoreEnv);
	~CNetwork();
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	INetServer *StartServer() override;
	INetClient *StartClient() override;
	
	const char *GetSubSystemName() const override {return "Network";}
private:
	std::unique_ptr<INetServer> mpServer;
	std::unique_ptr<INetClient> mpClient;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz