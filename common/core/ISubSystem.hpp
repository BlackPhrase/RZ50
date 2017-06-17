#pragma once

namespace rz
{

struct TCoreEnv;

struct ISubSystem // ICoreComponent
{
	/// Precondition for subsystem init
	/// @return true if we should continue and init the subsystem
	//virtual bool PreInit() = 0;
	
	/// Subsystem initialization
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	
	/// Called after subsystem was initialized
	//virtual void PostInit() = 0;
	
	/// This method will be called when the subsystem gets shutdown
	virtual void Shutdown() = 0;
	
	/// @return true if should apply an update
	//virtual bool PreUpdate() = 0;
	
	/// Update the subsystem
	virtual void Update() = 0;
	
	///
	//virtual void PostUpdate();
	
	/// @return The subsystem's name
	virtual const char *GetSubSystemName() const = 0; // GetName?
	
	/// @return true if successfully initialized (purpose?)
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