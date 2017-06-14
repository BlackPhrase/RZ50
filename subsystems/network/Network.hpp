#pragma once

#include "core/ISubSystem.hpp"
#include "network/INetwork.hpp"

namespace rz
{

class CNetwork final : public ISubSystem, INetwork
{
public:
	CNetwork() = default;
	~CNetwork() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	INetServer *StartServer();
	INetClient *StartClient();
private:
	std::unique_ptr<INetServer> mpServer;
	std::unique_ptr<INetClient> mpClient;
	
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz