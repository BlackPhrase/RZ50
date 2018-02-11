#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct ITexture;

struct TColor4
{
	byte r;
	byte g;
	byte b;
	byte a;
};

struct IRender
{
	///
	virtual bool Init(tWinHandle aWinHandle, int anPosX, int anPosY, int anWidth, int anHeight) = 0;
	
	///
	virtual void Shutdown() = 0;
	
	///
	virtual void FrameBegin() = 0;
	
	///
	virtual void FrameEnd() = 0;
	
	///
	virtual void SetClearColor(const TColor4 &aColor) = 0;
	
	///
	virtual void ClearScreen() = 0;
	
	///
	//virtual void SwapBuffers() = 0;
	
	/// TEXTURES
	
	///
	virtual ITexture *CreateTexture(int anWidth, int anHeight, int anBPP) = 0;
	
	///
	virtual void DestroyTexture(ITexture *apTexture) = 0;
};

}; // namespace rz