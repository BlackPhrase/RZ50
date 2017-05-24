#include "SubSystemManager.hpp"

namespace rz
{

bool CSubSystemManager::Init(const TCoreEnv &aCoreEnv)
{
	mpLog = aCoreEnv.pLog;
	
	for(auto It : mlstSubSystems)
		if(!It->Init(aCoreEnv))
		{
			mpLog->Write("Cannot init the engine because of the %s subsystem!", It->GetName());
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

bool Add(ISubSystem *apSubSystem)
{
	char *sName = apSubSystem->GetName();
	
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetName(), sName))
		{
			mpLog->Write("Cannot register the subsystem %s - already registered!", sName);
			return false;
		};
	
	mlstSubSystems.push_back(apSubSystem);
	return true;
};

ISubSystem *GetByName(const char *asName)
{
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz