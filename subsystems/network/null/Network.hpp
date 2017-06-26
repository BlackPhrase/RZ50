#pragma once

#include <memory>
#include "core/TCoreEnv.hpp"
#include "network/INetwork.hpp"

namespace rz
{

class CNetwork final : public INetwork
{
public:
	CNetwork(const TCoreEnv &aCoreEnv);
	~CNetwork();
	
	INetServer *StartServer() override;
	INetClient *StartClient() override;
private:
	std::unique_ptr<INetServer> mpServer;
	std::unique_ptr<INetClient> mpClient;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz