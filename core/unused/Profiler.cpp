#include "Profiler.hpp"

namespace rz
{

bool CProfiler::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Profiler");
	return true;
};

void CProfiler::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Profiler");
};

void CProfiler::Update()
{
};

void CProfiler::OnEvent(const TEvent &aEvent)
{
	switch(aEvent.eType)
	{
	};
};

}; // namespace rz