#pragma once

namespace rz
{

struct IServiceLocator;

struct IModule
{
	/// Precondition for module init
	/// @return true if we should continue and init the module
	//virtual bool PreInit() = 0;
	
	/// Module initialization
	virtual bool Init(const IServiceLocator &aCoreEnv) = 0;
	
	/// Called after module was initialized
	//virtual void PostInit() = 0;
	
	/// This method will be called when the module gets shutdown
	virtual void Shutdown() = 0;
	
	/// @return module name
	virtual const char *GetModuleName() const = 0; // GetName?
	
	/// @return true if successfully initialized (purpose?)
	//virtual bool IsInitialized() const = 0;
};

using pfnGetModule = IModule *(*)();

}; // namespace rz