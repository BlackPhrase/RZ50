#include "SubSystemContainer.hpp"
#include "core/ISubSystem.hpp"
#include "core/TCoreEnv.hpp"
#include "core/CoreTypes.hpp"

namespace rz
{

bool CSubSystemContainer::Init(TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("SubSystemManager");
	
	aCoreEnv.pSubSystemManager = this;
	return true;
};

void CSubSystemContainer::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("SubSystemManager");
	
	for(auto It : mlstSubSystems)
	{
		mCoreEnv.pLog->TraceShutdown(string(It->GetSubSystemName()).append(" SubSystem").c_str());
		It->Shutdown();
	};
};

void CSubSystemContainer::Update()
{
	for(auto It : mlstSubSystems)
	{
		//mpUpdateLog->TraceUpdate(It->GetSubSystemName());
		It->Update();
	};
};

bool CSubSystemContainer::Add(const ISubSystem &apSubSystem)
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

//void CSubSystemContainer::Remove(const ISubSystem &aSubSystem)
//{
//};

ISubSystem *CSubSystemContainer::GetByName(const char *asName) const
{
	for(auto It : mlstSubSystems)
		if(!strcmp(It->GetSubSystemName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz