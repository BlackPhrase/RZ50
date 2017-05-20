#pragma once

#include <memory>
#include "INetwork.hpp"

class CNetwork : public INetwork
{
public:
	CNetwork() = default;
	~CNetwork() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	INetServer *StartServer();
	INetClient *StartClient();
private:
	std::unique_ptr<INetServer> mpServer;
	std::unique_ptr<INetClient> mpClient;
};