#pragma once

#include "core/ISubSystem.hpp"
#include "sound/ISound.hpp"

class CLoggedSound : public ISubSystem, ISound
{
public:
	CLoggedSound(const ISound &aImpl) : mpImpl(*aImpl){}
	~CLoggedSound() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	ISoundWorld *CreateWorld();
	
	const char *GetSubSystemName() const {return "Sound";}
private:
	ISound *mpImpl{nullptr};
};