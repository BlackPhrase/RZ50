#pragma once

#include "ISound.hpp"

class CLoggedSound : public ISound
{
public:
	CLoggedSound(const ISound &aImpl) : mpImpl(*aImpl){}
	~CLoggedSound() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
private:
	ISound *mpImpl{nullptr};
};