#include "System.hpp"

//DECLARE_SUBSYSTEM(CSystem, GetSystemSubSystem)

C_EXPORT rz::ISubSystem *GetSystemSubSystem()
{
	static CSystem System;
	return &System;
};