#pragma once

namespace rz
{

struct TCoreEnv;

struct ISubSystem
{
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
	
	virtual const char *GetSubSystemName() const = 0; // GetName?
	
	//virtual bool IsInitialized() const = 0;
};

template<typename T>
class CBaseSubSystem : public T
{
	//virtual bool Init(const TCoreEnv &aCoreEnv){return T->Init(aCoreEnv);}
	//virtual void Shutdown(){T->Shutdown();}
	//virtual void Update(){T->Update();}
	
	//virtual bool IsInitialized() const = 0;
protected:
	//T mT;
};

}; // namespace rz