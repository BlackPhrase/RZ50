#include "LoggedGame.hpp"
#include "Game.hpp"

//DECLARE_SUBSYSTEM(CGame, GetGameSubSystem)

#ifndef RZ_STATIC_GAME
	extern "C" EXPORT
#endif // RZ_STATIC_GAME

rz::ISubSystem *GetGameSubSystem()
{
	static rz::ISubSystem *pGame = 
	
#ifdef RZ_LOGGED_GAME
	new rz::CLoggedGame(
#endif

	new rz::CGame()
	
#ifdef RZ_LOGGED_GAME
	);
#endif
	
	return pGame;
};