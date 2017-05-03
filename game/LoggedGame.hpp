#pragma once

#include "ISubSystem.hpp"
#include "game/IGame.hpp"

class CLoggedGame final : public ISubSystem<IGame>
{
public:
	CLoggedGame(const IGame &aImpl) : mpImpl(*aImpl){}
	~CLoggedGame() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "Game";}
private:
	IGame *mpImpl{nullptr};
};