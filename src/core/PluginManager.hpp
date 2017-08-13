#pragma once

#include <memory>
#include <list>
#include "core/IPluginManager.hpp"
#include "shiftutil/SharedLib.hpp"

namespace rz
{

struct TCoreEnv;
class CPluginLoader;

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

class CPluginManager final : public IPluginManager
{
public:
	CPluginManager(const TCoreEnv &aCoreEnv);
	~CPluginManager();
	
	bool Init(TCoreEnv &aCoreEnv);
	void Shutdown();
	
	bool LoadPlugin(const char *asName) override;
	void UnloadAllPlugins();
private:
	tSharedLibList mlstPluginLibs;
	tPluginList mlstPlugins;
	
	//tPluginHandleList mlstPlugins;
	
	std::unique_ptr<CPluginLoader> mpLoader;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz