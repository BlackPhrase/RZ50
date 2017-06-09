#pragma once

#include "core/ISubSystem.hpp"
#include "physics/IPhysics.hpp"

namespace rz
{

class CPhysics final : public ISubSystem, IPhysics
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Physics";}
private:
	const TCoreEnv *mpCoreEnv{nullptr};
};

}; // namespace rz