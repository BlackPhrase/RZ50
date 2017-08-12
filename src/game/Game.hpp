#pragma once

#include "core/ISubSystem.hpp"
#include "game/IGame.hpp"

class CGame final : public rz::ISubSystem, rz::IGame
{
public:
	CGame(const rz::TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CGame() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Game";}
private:
	const rz::TCoreEnv &mpCoreEnv;
};