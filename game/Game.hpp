#pragma once

#include "IGame.hpp"

class CGame : public IGame
{
public:
	CGame() = default;
	~CGame() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
};