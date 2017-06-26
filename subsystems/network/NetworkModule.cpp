#include "NetworkModule.hpp"

namespace rz
{

bool CNetworkModule::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Network");
	mCoreEnv.pLog->Info("Network: Null");
	return true;
};

void CNetworkModule::Shutdown()
{
};

void CNetworkModule::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Network");
	
	//if(mpNetwork)
		//mpNetwork->Update();
};

}; // namespace rz