#pragma once

#include "IGame.hpp"

class CLoggedGame : public IGame
{
public:
	CLoggedGame(const IGame &aImpl) : mpImpl(*aImpl){}
	~CLoggedGame() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
private:
	IGame *mpImpl{nullptr};
};