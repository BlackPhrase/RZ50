#include "Game.hpp"

//DECLARE_SUBSYSTEM(CGame, GetGameSubSystem)

C_EXPORT rz::ISubSystem *GetGameSubSystem()
{
	static CGame Game;
	return &Game;
};