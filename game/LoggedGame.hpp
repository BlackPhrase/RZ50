#pragma once

#include "ISubSystem.hpp"
#include "game/IGame.hpp"

class CLoggedGame : public ISubSystem<IGame>
{
public:
	CLoggedGame(const IGame &aImpl) : mpImpl(*aImpl){}
	~CLoggedGame() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	const char *GetSubSystemName() const {return "Game";}
private:
	IGame *mpImpl{nullptr};
};