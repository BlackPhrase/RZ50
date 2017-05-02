#pragma once

#include "ISubSystem.hpp"
#include "system/ISystem.hpp"

class CSystem : public ISubSystem<ISystem>
{
public:
	CSystem() = default;
	~CSystem() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "System";}
};