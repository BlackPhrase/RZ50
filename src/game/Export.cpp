#include "Game.hpp"

//DECLARE_SUBSYSTEM(CGame, GetGameSubSystem)

C_EXPORT rz::ISubSystem *GetGame(const rz::TCoreEnv &aCoreEnv)
{
	static CGame Game(aCoreEnv);
	return &Game;
};