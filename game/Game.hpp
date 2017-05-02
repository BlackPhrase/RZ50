#pragma once

#include "ISubSystem.hpp"
#include "game/IGame.hpp"

class CGame : public ISubSystem<IGame>
{
public:
	CGame() = default;
	~CGame() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Game";}
};