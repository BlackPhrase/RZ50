#pragma once

namespace rz
{

struct IServiceLocator;

struct IGraphicsImpl
{
	virtual bool Init(const IServiceLocator &aCoreEnv) = 0;
	
	virtual bool OpenWindow(int anWidth, int anHeight) = 0;
	
	virtual void ProcessEvents() = 0;
};

}; // namespace rz