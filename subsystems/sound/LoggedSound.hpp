#pragma once

#include "ISubSystem.hpp"
#include "sound/ISound.hpp"

class CLoggedSound : public ISubSystem<ISound>
{
public:
	CLoggedSound(const ISound &aImpl) : mpImpl(*aImpl){}
	~CLoggedSound() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	ISoundWorld *CreateWorld();
	
	const char *GetSubSystemName() const {return "Sound";}
private:
	ISound *mpImpl{nullptr};
};