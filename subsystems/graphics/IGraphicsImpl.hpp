#pragma once

namespace rz
{

struct TCoreEnv;

struct IGraphicsImpl
{
	virtual bool Init(const TCoreEnv &aCoreEnv) = 0;
	
	virtual bool OpenWindow() = 0;
	
	virtual void ProcessEvents() = 0;
};

}; // namespace rz