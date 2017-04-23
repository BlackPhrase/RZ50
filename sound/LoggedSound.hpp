#pragma once

#include "ISound.hpp"

class CLoggedSound : public ISound
{
public:
	CLoggedSound(const ISound &aImpl) : mpImpl(*aImpl){}
	~CLoggedSound() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
private:
	ISound *mpImpl{nullptr};
};