#pragma once

#include "ISubSystem.hpp"
#include "physics/IPhysics.hpp"

namespace rz
{

class CLoggedPhysics final : public ISubSystem<IPhysics>
{
public:
	CLoggedPhysics(const IPhysics &aImpl) : mpImpl(*aImpl){}
	~CLoggedPhysics() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Physics;}
private:
	IPhysics *mpImpl{nullptr};
};

}; // namespace rz