#include "ModuleContainer.hpp"
#include "core/IModule.hpp"
#include "core/TServiceLocator.hpp"
#include "core/CoreTypes.hpp"

namespace rz
{

bool CModuleContainer::Init(IServiceLocator &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("ModuleManager");
	
	aCoreEnv.pModuleContainer = this;
	return true;
};

void CModuleContainer::Shutdown()
{
	mCoreEnv.pLog->TraceShutdown("ModuleManager");
	
	for(auto It : mlstModules)
	{
		mCoreEnv.pLog->TraceShutdown(string(It->GetModuleName()).append(" Module").c_str());
		It->Shutdown();
	};
};

void CModuleContainer::Update()
{
	for(auto It : mlstModules)
	{
		//mpUpdateLog->TraceUpdate(It->GetModuleName());
		It->Update();
	};
};

bool CModuleContainer::Add(const IModule &aModule)
{
	const char *sName = aModule.GetModuleName();
	
	for(auto It : mlstModules)
		if(!strcmp(It->GetModuleName(), sName))
		{
			mCoreEnv->GetLog()->Error("Cannot register the module %s - already registered!", sName);
			return false;
		};
	
	auto *pModule = const_cast<IModule*>(&aModule);
	mlstModules.push_back(pModule);
	
	pModule->Init(mCoreEnv); // temp
	return true;
};

//void CModuleContainer::Remove(const IModule &aModule)
//{
//};

ISubSystem *CModuleContainer::GetByName(const char *asName) const
{
	for(auto It : mlstModules)
		if(!strcmp(It->GetModuleName(), asName))
			return It;
	
	return nullptr;
};

}; // namespace rz