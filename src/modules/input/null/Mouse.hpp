#pragma once

#include "input/IMouse.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CNullMouse final : public IMouse
{
public:
	CNullMouse(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CNullMouse() = default;
	
	void Update() override;
	
	bool IsButtonPressed(Button aeButton) const override;
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz