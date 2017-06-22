#pragma once

namespace rz
{

struct ISubSystem;

struct ISubSystemManager
{
	///
	virtual void RegisterSubSystem(const ISubSystem &aSubSystem) = 0;
	
	///
	virtual void UnregisterSubSystem(const ISubSystem &aSubSystem) = 0;
	
	///
	virtual ISubSystem *GetSubSystem(const char *asName) const = 0;
	
	///
	template<typename T>
	inline T *GetSubSystem() const {return GetSubSystem(T);}
};

}; // namespace rz