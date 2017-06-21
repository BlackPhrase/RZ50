#include "Network.hpp"
#include "NetServer.hpp"
#include "NetClient.hpp"

namespace rz
{

CNetwork::CNetwork(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
CNetwork::~CNetwork() = default;

bool CNetwork::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Network");
	mCoreEnv.pLog->Info("Network: Null");
	return true;
};

void CNetwork::Shutdown()
{
};

void CNetwork::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Network");
	
	//if(mpServer)
		//mpServer->Update();
	
	//if(mpClient)
		//mpClient->Update();
};

INetServer *CNetwork::StartServer()
{
	mpServer = std::make_unique<CNetServer>();
	return mpServer.get();
};

INetClient *CNetwork::StartClient()
{
	mpClient = std::make_unique<CNetClient>();
	return mpClient.get();
};

}; // namespace rz