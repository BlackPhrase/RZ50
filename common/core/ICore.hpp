#pragma once

namespace rz
{

struct ICore
{
	//virtual void Frame() = 0;
	//virtual void Run() = 0;
	//virtual bool IsCloseRequested() const = 0; // WantQuit
	
	virtual ILog *GetLog() const = 0;
	virtual IMemory *GetMemory() const = 0;
	//virtual IEventManager *GetEventManager() const = 0;
	//virtual IFileSystem *GetFileSystem() const = 0;
	
	virtual void GetEnv(TCoreEnvironment &aCoreEnv) = 0;
	
	virtual void RegisterSubSystem(ISubSystem &apSubSystem) = 0;
	virtual ISubSystem *GetSubSystem(const char *asName) const = 0;
};

}; // namespace rz