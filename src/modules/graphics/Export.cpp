#include "core/CoreTypes.hpp"
#include "GraphicsModule.hpp"

//DECLARE_SUBSYSTEM(CGraphics, GetGraphicsSubSystem)

C_EXPORT rz::IModule *GetModule(const rz::IServiceLocator &aCoreEnv)
{
	static rz::CGraphicsModule GraphicsModule;
	return &GraphicsModule;
};