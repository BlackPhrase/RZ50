#include "SubSystemManager.hpp"
#include "core/ISubSystem.hpp"
#include "core/TCoreEnv.hpp"
#include "core/ILog.hpp"
#include "core/CoreTypes.hpp"

namespace rz
{

bool CSubSystemManager::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = const_cast<TCoreEnv*>(&aCoreEnv);
	mpLog = aCoreEnv.pLog;
	
	for(auto It : mlstSubSystems)
		if(!It->Init(aCoreEnv))
		{
			mpLog->Error("Cannot init the engine because of the %s subsystem!", It->GetSubSystemName());
			return false;
		};
	
	return true;
};

void CSubSystemManager::Shutdown()
{
	for(auto It : mlstSubSystems)
		It->Shutdown();
};

void CSubSystemManager::Update()
{
	for(auto It : mlstSubSystems)
		It->Update();
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