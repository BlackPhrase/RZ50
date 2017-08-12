#pragma once

#include <gl/GL.h>

#ifdef _WIN32
#else
	// TODO
	#include <gl/glx.h>
#endif

#include "IRender.hpp"

namespace rz
{

class CRenderGL final : public IRender
{
public:
	CRenderGL() = default;
	~CRenderGL() = default;
	
	bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) override;
	void Shutdown() override;
	
	void FrameBegin() override;
	void FrameEnd() override;
	
	void SetClearColor(const TColor4 &aColor) override;
	
	void ClearScreen() override;
private:
	tWinHandle mWinHandle;
	
#ifdef _WIN32
	HDC hDeviceContext;
	HGLRC hGLRC;
#else
	// TODO
#endif
	
	bool CreateContext();
	void FreeContext();
};

}; // namespace rz