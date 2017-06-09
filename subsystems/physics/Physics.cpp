#include "Physics.hpp"

namespace rz
{

bool CPhysics::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Physics");
	return true;
};

void CPhysics::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Physics");
};

void CPhysics::Update()
{
	//mpCoreEnv->pUpdateLog->TraceUpdate("Physics");
};

}; // namespace rz