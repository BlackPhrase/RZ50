#pragma once

#include <list>
#include "core/IPluginManager.hpp"
#include "shiftutil/SharedLib.hpp"

namespace rz
{

struct TCoreEnv;

using tSharedLib = class shiftutil::CSharedLib;
using tSharedLibList = std::list<tSharedLib*>;

struct IPlugin;
using tPluginList = std::list<IPlugin*>;

class CPluginHandle;
using tPluginHandleList = std::list<CPluginHandle*>;

class CPluginHandle
{
public:
	//CPluginHandle(tSharedLib ahLib, IPlugin *apPlugin)
	//	: mhLib(ahLib), mpPlugin(apPlugin){}
	~CPluginHandle() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
private:
	tSharedLib mhLib{0};
	IPlugin *mpPlugin{nullptr};
};

class CPluginManager : public IPluginManager
{
public:
	CPluginManager() = default;
	~CPluginManager() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	bool LoadPlugin(const char *asName);
	void UnloadAllPlugins();
	
	void RegisterSubSystem(const ISubSystem &aSubSystem);
	void UnregisterSubSystem(const ISubSystem &aSubSystem);
	
	void *GetSubSystem(const char *asName) const;
private:
	tSharedLibList mlstPluginLibs;
	tPluginList mlstPlugins;
	
	//tPluginHandleList mlstPlugins;
	
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz