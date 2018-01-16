#include "core/CoreTypes.hpp"
#include "InputModule.hpp"

//DECLARE_SUBSYSTEM(CInput, GetInputSubSystem)

C_EXPORT rz::IModule *GetModule(const rz::IServiceLocator &aCoreEnv)
{
	static rz::CInputModule InputModule(aCoreEnv);
	return &InputModule;
};