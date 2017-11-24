#pragma once

#include <list>
#include "core/IModuleContainer.hpp"

namespace rz
{

struct IServiceLocator;

struct IModule;
using tModuleList = std::list<IModule*>;

class CModuleContainer : public IModuleContainer
{
public:
	CModuleContainer(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CModuleContainer() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
	
	bool Add(const IModule &aModule);
	//void Remove(const IModule &aModule);
	
	IModule *GetByName(const char *asName) const;
	//IModule *GetByIndex(int anID);
private:
	tModuleList mlstModules;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz