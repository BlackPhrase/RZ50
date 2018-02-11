#include "core/IServiceLocator.hpp"
#include "GraphicsModule.hpp"
#include "Graphics.hpp"
#include "render/IRender.hpp"

#ifdef _WIN32
	#include "impl/win/GraphicsWin.hpp"
#else
	#include "impl/unix/GraphicsUnix.hpp"
#endif

namespace rz
{

IRender *LoadRenderModule(const char *name)
{
	IRender *pRender{nullptr};
	
	return pRender;
};

bool CGraphicsModule::Init(const IServiceLocator &aCoreEnv)
{
#ifdef _WIN32
	static rz::CGraphicsWin GraphicsImpl;
#elif
	static rz::CGraphicsUnix GraphicsImpl;
#endif
	
	IRender *pRender = LoadRenderModule("RZRender-GL2");
	static rz::CGraphics Graphics(aCoreEnv, &GraphicsImpl, pRender);
	
	return true;
};

void CGraphicsModule::Shutdown()
{
};

}; // namespace rz