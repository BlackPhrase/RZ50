#pragma once

#include "ISound.hpp"

class CSound : public ISound
{
public:
	CSound() = default;
	~CSound() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
};