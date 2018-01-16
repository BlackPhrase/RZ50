#include "core/IServiceLocator.hpp"
#include "GraphicsModule.hpp"
#include "Graphics.hpp"
#include "RenderGL.hpp"

#ifdef _WIN32
	#include "impl/win/GraphicsWin.hpp"
#else
	#include "impl/unix/GraphicsUnix.hpp"
#endif

namespace rz
{

bool CGraphicsModule::Init(const IServiceLocator &aCoreEnv)
{
#ifdef _WIN32
	static rz::CGraphicsWin GraphicsImpl;
#elif
	static rz::CGraphicsUnix GraphicsImpl;
#endif

	static rz::CRenderGL RenderGL;
	
	static rz::CGraphics Graphics(aCoreEnv, &GraphicsImpl, &RenderGL);
	
	return true;
};

void CGraphicsModule::Shutdown()
{
};

}; // namespace rz