#include "core/CoreTypes.hpp"
#include "Graphics.hpp"
#include "RenderGL.hpp"

#ifdef _WIN32
	#include "impl/win/GraphicsWin.hpp"
#else
	#include "impl/unix/GraphicsUnix.hpp"
#endif

//DECLARE_SUBSYSTEM(CGraphics, GetGraphicsSubSystem)

C_EXPORT rz::IModule *GetGraphics(const rz::IServiceLocator &aCoreEnv)
{
#ifdef _WIN32
	static rz::CGraphicsWin GraphicsImpl;
#elif
	static rz::CGraphicsUnix GraphicsImpl;
#endif

	static rz::CRenderGL RenderGL;
	
	static rz::CGraphics Graphics(aCoreEnv, &GraphicsImpl, &RenderGL);
	return &Graphics;
};