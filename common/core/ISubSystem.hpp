#pragma once

namespace rz
{

struct TCoreEnv;

template<typename T>
struct ISubSystem : public T // hmm...
{
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetSubSystemName() const = 0; // GetName?
	
	//virtual bool IsInitialized() const = 0;
};

}; // namespace rz