#include "core/CoreTypes.hpp"
#include "Input.hpp"

//DECLARE_SUBSYSTEM(CInput, GetInputSubSystem)

C_EXPORT rz::ISubSystem *GetInputSubSystem()
{
	static rz::CInput Input;
	return &Input;
};