#include "LoggedGame.hpp"
#include "Game.hpp"

//DECLARE_SUBSYSTEM(CGame, GetGameSubSystem)

#ifndef RZ_STATIC_GAME
	extern "C" EXPORT
#endif // RZ_STATIC_GAME

ISubSystem *GetGameSubSystem()
{
	static ISubSystem *pGame = 
	
#ifdef RZ_LOGGED_GAME
	new CLoggedGame(
#endif

	new CGame()
	
#ifdef RZ_LOGGED_GAME
	);
#endif
	
	return pGame;
};