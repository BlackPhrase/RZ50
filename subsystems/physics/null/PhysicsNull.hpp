#pragma once

#include "core/TCoreEnv.hpp"
#include "physics/IPhysics.hpp"

namespace rz
{

class CPhysics final : public IPhysics
{
public:
	CPhysics(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CPhysics() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Physics";}
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz