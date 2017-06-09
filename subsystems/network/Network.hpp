#pragma once

#include "core/ISubSystem.hpp"
#include "network/INetwork.hpp"

namespace rz
{

class CNetwork : public ISubSystem, INetwork
{
public:
	CNetwork() = default;
	~CNetwork() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	INetServer *StartServer();
	INetClient *StartClient();
private:
	std::unique_ptr<INetServer> mpServer;
	std::unique_ptr<INetClient> mpClient;
	
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz