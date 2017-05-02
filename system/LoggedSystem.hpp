#pragma once

#include "ISubSystem.hpp"
#include "system/ISystem.hpp"

class CLoggedSystem : public ISubSystem<ISystem>
{
public:
	CLoggedSystem(const ISystem &aImpl) : mpImpl(*aImpl){}
	~CLoggedSystem() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "System";}
private:
	ISystem *mpImpl{nullptr};
};