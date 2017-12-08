#include <cstdio>
#include "EngineWrapper.hpp"

bool CEngineWrapper::Init(const rz::TCoreInitParams &aInitParams)
{
	if(mpCore)
		return mpCore->Init(aInitParams);

	return false;
};

void CEngineWrapper::Shutdown()
{
	if(mpCore)
		mpCore->Shutdown();
};

void CEngineWrapper::Run()
{
	if(!mpCore)
		return;

	while(!mpCore->IsCloseRequested()) //WantQuit())
	{
		//if(!ProcessEvents())
			//break;
		//else
			mpCore->Frame(); // update the core and each registered module
	};
	
	//Shutdown();
};

const rz::IServiceLocator *CEngineWrapper::GetEnv() const
{
	if(mpCore)
		return &mpCore->GetEnv();

	return nullptr;
};