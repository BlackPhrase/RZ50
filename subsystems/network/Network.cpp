#include "Network.hpp"
#include "NetServer.hpp"
#include "NetClient.hpp"

namespace rz
{

bool CNetwork::Init(const TCoreEnvironment &aCoreEnv)
{
	return true;
};

void CNetwork::Shutdown()
{
};

void CNetwork::Update()
{
	if(mpNetServer)
		mpNetServer->Update();
	
	if(mpNetClient)
		mpNetClient->Update();
};

INetServer *CNetwork::StartServer()
{
	mpNetServer = std::make_unique<CNetServer>();
	return mpNetServer.get();
};

INetClient *CNetwork::StartClient()
{
	mpNetClient = std::make_unique<CNetClient>();
	return mpNetClient.get();
};

}; // namespace rz