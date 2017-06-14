#include "Network.hpp"
#include "NetServer.hpp"
#include "NetClient.hpp"

namespace rz
{

bool CNetwork::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Network");
	return true;
};

void CNetwork::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Network");
};

void CNetwork::Update()
{
	//mpCoreEnv->pUpdateLog->TraceUpdate("Network");
	
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