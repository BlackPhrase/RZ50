#include "RenderGL.hpp"

namespace rz
{

bool CRenderGL::Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight)
{
	mWinHandle = aWinHandle;
	
	//glViewport(anPosX, anPosY, anWidth, anHeight);
	
	if(!CreateContext())
		return false;
	
	return true;
};

void CRenderGL::Shutdown()
{
	FreeContext();
};

void CRenderGL::FrameBegin()
{
	//glBegin(GL_TRIANGLES);
};

void CRenderGL::FrameEnd()
{
	//glEnd();
};

void CRenderGL::SetClearColor(const TColor4 &aColor)
{
	//glClearColor((GLfloat)aColor.r, (GLfloat)aColor.g, (GLfloat)aColor.b, (GLfloat)aColor.a);
};

void CRenderGL::ClearScreen()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

bool CRenderGL::CreateContext()
{
#ifdef _WIN32
	//mhDeviceContext = GetDC(mWinHandle);
	//mhGLRC = wglCreateContext(hDeviceContext);
	
	//wglMakeCurrent(mhDeviceContext, mhGLRC);
#else
	// TOOD
	//GL hGLRC = glXCreateContext();
#endif

	return false;
};

void CRenderGL::FreeContext()
{
#ifdef _WIN32
	//wglMakeCurrent(nullptr, nullptr);
	//wglDeleteContext(mhGLRC);
	//ReleaseDC(mWinHandle, mhDeviceContext);
#else
	// TODO
#endif
};

}; // namespace rz