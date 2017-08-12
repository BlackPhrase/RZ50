#include "SubSystemManager.hpp"
#include "core/ISubSystem.hpp"
#include "core/TCoreEnv.hpp"
#include "core/CoreTypes.hpp"

namespace rz
{

bool CSubSystemManager::Init(TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("SubSystemManager");
	
	aCoreEnv.pSubSystemManager = this;
	return true;
};

void CSubSystemManager::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("SubSystemManager");
	
	for(auto It : mlstSubSystems)
	{
		mCoreEnv.pLog->TraceShutdown(string(It->GetSubSystemName()).append(" SubSystem").c_str());
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
			mCoreEnv.pLog->Error("Cannot register the subsystem %s - already registered!", sName);
			return false;
		};
	
	auto *pSubSystem = const_cast<ISubSystem*>(&apSubSystem);
	mlstSubSystems.push_back(pSubSystem);
	
	pSubSystem->Init(mCoreEnv); // temp
	return true;
};

//void CSubSystemManager::Remove(const ISubSystem &aSubSystem)
//{
//};

ISubSystem *CSubSystemManager::GetByName(const char *asName) const
{
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetSubSystemName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz