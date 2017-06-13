#include "core/CoreTypes.hpp"
#include "Graphics.hpp"

#ifdef _WIN32
	#include "impl/win/GraphicsWin.hpp"
#else
	#include "impl/unix/GraphicsUnix.hpp"
#endif

//DECLARE_SUBSYSTEM(CGraphics, GetGraphicsSubSystem)

C_EXPORT rz::ISubSystem *GetGraphics()
{
#ifdef _WIN32
	static rz::CGraphicsWin GraphicsImpl;
#elif
	static rz::CGraphicsUnix GraphicsImpl;
#endif
	
	static rz::CGraphics Graphics(&GraphicsImpl);
	return &Graphics;
};