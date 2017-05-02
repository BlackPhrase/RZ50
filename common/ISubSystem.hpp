#pragma once

template<typename T>
struct ISubSystem : public T // hmm...
{
	//inline bool Init(const TCoreEnvironment &aCoreEnv){T->Init(aCoreEnv);}
	//inline void Shutdown(){T->Shutdown();}
	
	//inline void Update(){T->Update();}
	
	virtual const char *GetSubSystemName() = 0;
};