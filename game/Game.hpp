#pragma once

#include "ISubSystem.hpp"
#include "game/IGame.hpp"

class CGame final : public ISubSystem<IGame>
{
public:
	CGame() = default;
	~CGame() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Game";}
};