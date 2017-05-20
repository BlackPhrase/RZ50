#pragma once

#include "ISubSystem.hpp"
#include "system/ISystem.hpp"

namespace rz
{

class CLoggedSystem final : public ISubSystem<ISystem>
{
public:
	CLoggedSystem(const ISystem &aImpl) : mpImpl(*aImpl){}
	~CLoggedSystem() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "System";}
private:
	ISystem *mpImpl{nullptr};
};

}; // namespace rz