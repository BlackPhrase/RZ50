#pragma once

#include "ISubSystem.hpp"
#include "input/IInput.hpp"

class CLoggedInput final : public ISubSystem<IInput>
{
public:
	CLoggedInput(const IInput &aImpl) : mpImpl(*aImpl){}
	~CLoggedInput() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Input";}
private:
	IInput *mpImpl{nullptr};
};