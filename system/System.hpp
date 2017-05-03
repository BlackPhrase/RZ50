#pragma once

#include "ISubSystem.hpp"
#include "system/ISystem.hpp"

class CSystem final : public ISubSystem<ISystem>
{
public:
	CSystem() = default;
	~CSystem() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "System";}
};