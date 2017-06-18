#pragma once

#include "input/IMouse.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CNullMouse final : public IMouse
{
public:
	CNullMouse(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CNullMouse() = default;
	
	void Update() override;
	
	bool IsButtonPressed(Button aeButton) const override;
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz