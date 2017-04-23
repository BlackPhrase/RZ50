#pragma once

#include "IPhysics.hpp"

class CLoggedPhysics : public IPhysics
{
public:
	CLoggedPhysics(const IPhysics &aImpl) : mpImpl(*aImpl){}
	~CLoggedPhysics() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
private:
	IPhysics *mpImpl{nullptr};
};