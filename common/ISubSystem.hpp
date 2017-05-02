#pragma once

struct TCoreEnvironment;

template<typename T>
struct ISubSystem : public T // hmm...
{
	virtual bool Init(const TCoreEnvironment &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetSubSystemName() const = 0;
	
	//virtual bool IsInitialized() const = 0;
};

struct ISomeSystem
{
	// Init/Shutdown/Update can be omitted using the ISubSystem
	
	virtual void Blah() = 0;
};