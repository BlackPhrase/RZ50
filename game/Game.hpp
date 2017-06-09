#pragma once

#include "core/ISubSystem.hpp"
#include "game/IGame.hpp"

class CGame final : public ISubSystem, IGame
{
public:
	CGame() = default;
	~CGame() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Game";}
private:
	const TCoreEnv *mpCoreEnv{nullptr};
};