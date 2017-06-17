#include "core/CoreTypes.hpp"
#include "Input.hpp"

//DECLARE_SUBSYSTEM(CInput, GetInputSubSystem)

C_EXPORT rz::ISubSystem *GetInput(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CInput Input(aCoreEnv);
	return &Input;
};