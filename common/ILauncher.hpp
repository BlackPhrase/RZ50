#pragma once

struct ILauncher
{
	virtual bool Init() = 0;
	//virtual ICore *Init() = 0;
	virtual void Shutdown() = 0;
	
	//virtual void Run(ICore *apCore) = 0;
	virtual void Frame() = 0;
};

struct ICore
{
	//virtual void Frame() = 0;
	//virtual void Run() = 0;
	//virtual bool IsCloseRequested() = 0;
	
	virtual ILog *GetLog() = 0;
	virtual IMemory *GetMemory() = 0;
	//virtual IFileSystem *GetFileSystem() = 0;
	
	virtual void RegisterSubSystem(ISubSystem *apSubSystem) = 0;
	virtual ISubSystem *GetSubSystem(const char *asName) = 0;
};

struct IProfiler
{
	virtual IProfileTimer *StartTiming(const char *asName) = 0;
};

struct IProfileTimer
{
	virtual TProfileResult Stop() = 0;
};

struct ISubSystem
{
	virtual bool Init(const TCoreEnvironment &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetName() const = 0;
};