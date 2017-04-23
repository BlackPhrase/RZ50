#pragma once

#include "IGame.hpp"

class CGame : public IGame
{
public:
	CGame() = default;
	~CGame() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
};