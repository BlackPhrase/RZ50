#pragma once

namespace rz
{

struct TCoreEnvironment;

template<typename T>
struct ISubSystem : public T // hmm...
{
	virtual bool Init(const TCoreEnvironment &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetSubSystemName() const = 0; // GetName?
	
	//virtual bool IsInitialized() const = 0;
};

}; // namespace rz