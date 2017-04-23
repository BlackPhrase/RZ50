#pragma once

struct ILauncher
{
	virtual bool Init() = 0;
	virtual void Shutdown() = 0;
	
	virtual void Frame() = 0;
};