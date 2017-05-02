#pragma once

#include "ISubSystem.hpp"
#include "sound/ISound.hpp"

using tSoundChannelVec = std::vector<ISoundChannel*>;

class CSound : public ISubSystem<ISound>
{
public:
	CSound() = default;
	~CSound() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	ISoundChannel *CreateChannel();
	
	const char *GetSubSystemName() const {return "Sound";}
private:
	tSoundChannelVec mvChannels;
};