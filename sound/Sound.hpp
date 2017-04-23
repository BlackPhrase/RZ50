#pragma once

#include "ISound.hpp"

class CSound : public ISound
{
public:
	CSound() = default;
	~CSound() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
};