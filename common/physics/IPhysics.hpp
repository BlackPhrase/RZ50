#pragma once

struct TCoreEnvironment;

struct IPhysics
{
	virtual bool Init(const TCoreEnvironment &aCoreEnv) = 0;
	virtual void Shutdown() = 0;
	
	virtual void Update() = 0;
};