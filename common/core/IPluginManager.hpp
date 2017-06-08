#pragma once

namespace rz
{

struct ISubSystem;

struct IPluginManager
{
	///
	virtual void RegisterSubSystem(const ISubSystem &aSubSystem) = 0;
	
	///
	virtual void UnregisterSubSystem(const ISubSystem &aSubSystem) = 0;
	
	///
	//virtual ISubSystem *GetSubSsystem(const char *asName) const = 0;
	virtual void *GetSubSystem(const char *asName) const = 0;
	
	///
	template<typename T>
	inline T *GetSubSystem(const char *asName) const {return GetSubSystem(asName);}
};

}; // namespace rz