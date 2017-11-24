#include <cstdio>
#include "EngineProxy.hpp"

bool CEngineProxy::Load()
{
#ifndef RZ_CORE_STATIC
	rz::pfnGetCore fnGetCore{nullptr};
	
	if(!mCoreLib.Open("RZCore"))
		return false;
	
	fnGetCore = mCoreLib.GetExportFunc<rz::pfnGetCore>("GetCore");
	
	if(!fnGetCore)
		return false;
#else
	extern rz::ICore *fnGetCore();
#endif

	mpCore = fnGetCore();
	
	if(!mpCore)
	{
		printf("pCore is invalid! (%p)\n", mpCore);
		return false;
	};
	
	return true;
};

void CEngineProxy::Unload()
{
	if(!IsLoaded())
		return;
	
	Shutdown();
	
#ifndef RZ_CORE_STATIC
	// TODO: unload the core module
	// NOTE: Currently handled by shiftutil::CSharedLib which will 
	// free the lib at destruction
#endif
	
	mpCore = nullptr;
	
	//mCoreLib.Free();
	
	//return true;
};

bool CEngineProxy::IsLoaded() const
{
	if(mpCore)
		return true;
	
	return false;
};

bool CEngineProxy::Init(const rz::TCoreInitParams &aInitParams)
{
	if(!mpCore)
		return false;
	
	return mpCore->Init(aInitParams);
};

void CEngineProxy::Shutdown()
{
	if(!mpCore)
		return;
	
	mpCore->Shutdown();
};

void CEngineProxy::Run()
{
	if(!mpCore)
		return;
	
	while(!mpCore->IsCloseRequested()) //WantQuit())
	{
		//if(!ProcessEvents())
			//break;
		//else
			mpCore->Frame(); // update the core and each registered subsystem
	};
	
	//Shutdown();
};

const rz::IServiceLocator *CEngineProxy::GetEnv() const
{
	if(mpCore)
		return &mpCore->GetEnv();
	
	return nullptr;
};