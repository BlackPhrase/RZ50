#pragma once

#include "ISubSystem.hpp"
#include "physics/IPhysics.hpp"

namespace rz
{

class CPhysics final : public ISubSystem<IPhysics>
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Physics";}
};

}; // namespace rz