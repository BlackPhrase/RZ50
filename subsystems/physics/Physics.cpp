#include "Physics.hpp"

namespace rz
{

bool CPhysics::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Physics");
	mCoreEnv.pLog->Info("Physics: Null");
	return true;
};

void CPhysics::Shutdown()
{
};

void CPhysics::Update()
{
	//mCoreEnv.pUpdateLog->TraceUpdate("Physics");
};

}; // namespace rz