#pragma once

#include <GL/gl.h>

#ifdef _WIN32
#else
	// TODO
	#include <GL/glx.h>
#endif

#include "render/IRender.hpp"

namespace rz
{

class CRenderGL final : public IRender
{
public:
	CRenderGL() = default;
	~CRenderGL() = default;
	
	bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) override; // TODO: pass IWindow interface and get all these params from it!
	void Shutdown() override;
	
	void FrameBegin() override;
	void FrameEnd() override;
	
	void SetClearColor(const TColor4 &aColor) override;
	
	void ClearScreen() override;
	
	//void SwapBuffers() override;
	
	ITexture *CreateTexture(int anWidth, int anHeight, int anBPP) override;
	void DestroyTexture(ITexture *apTexture) override;
private:
	bool CreateContext();
	void FreeContext();
	
	tWinHandle mWinHandle;
	
#ifdef _WIN32
	HDC mhDeviceContext{0};
	HGLRC mhGLRC{0};
#else
	Display *mpDisplay{nullptr};
	GLXContext mhGLRC;
#endif
};

}; // namespace rz