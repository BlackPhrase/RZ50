#include "SubSystemManager.hpp"
#include "core/ISubSystem.hpp"
#include "core/TCoreEnv.hpp"
#include "core/ILog.hpp"
#include "core/CoreTypes.hpp"

namespace rz
{

bool CSubSystemManager::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	mpLog = aCoreEnv.pLog;
	
	mpLog->TraceInit("SubSystemManager");
	
	for(auto It : mlstSubSystems)
	{
		mpLog->TraceInit(It->GetSubSystemName());
		
		if(!It->Init(aCoreEnv))
		{
			mpLog->Error("Cannot init the engine because of the %s subsystem!", It->GetSubSystemName());
			return false;
		};
	};
	
	return true;
};

void CSubSystemManager::Shutdown()
{
	mpLog->TraceShutdown("SubSystemManager");
	
	for(auto It : mlstSubSystems)
	{
		mpLog->TraceShutdown(It->GetSubSystemName());
		It->Shutdown();
	};
};

void CSubSystemManager::Update()
{
	for(auto It : mlstSubSystems)
	{
		//mpUpdateLog->TraceUpdate(It->GetSubSystemName());
		It->Update();
	};
};

bool CSubSystemManager::Add(const ISubSystem &apSubSystem)
{
	const char *sName = apSubSystem.GetSubSystemName();
	
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetSubSystemName(), sName))
		{
			mpLog->Error("Cannot register the subsystem %s - already registered!", sName);
			return false;
		};
	
	auto *pSubSystem = const_cast<ISubSystem*>(&apSubSystem);
	mlstSubSystems.push_back(pSubSystem);
	return true;
};

ISubSystem *CSubSystemManager::GetByName(const char *asName)
{
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetSubSystemName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz