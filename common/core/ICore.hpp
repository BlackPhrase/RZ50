#pragma once

namespace rz
{

struct ISubSystem;

struct TCoreInitParams
{
	char sConfigName[32]; ///< Name of the config to use
};

struct ICore
{
	virtual bool Init(const TCoreInitParams &aParams) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Frame() = 0;
	//virtual void Run() = 0;
	//virtual bool IsCloseRequested() const = 0; // WantQuit
	
	//virtual ILog *GetLog() const = 0;
	//virtual IMemory *GetMemory() const = 0;
	//virtual IEventManager *GetEventManager() const = 0;
	//virtual IFileSystem *GetFileSystem() const = 0;
	
	//virtual void GetEnv(TCoreEnv &aCoreEnv) = 0;
	
	virtual bool RegisterSubSystem(const ISubSystem &apSubSystem) = 0;
	virtual ISubSystem *GetSubSystem(const char *asName) const = 0;
};

}; // namespace rz