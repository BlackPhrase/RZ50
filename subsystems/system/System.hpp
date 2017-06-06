#pragma once

#include "core/ISubSystem.hpp"
#include "system/ISystem.hpp"

namespace rz
{

class CSystem final : public ISubSystem, ISystem
{
public:
	CSystem() = default;
	~CSystem() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "System";}
};

}; // namespace rz