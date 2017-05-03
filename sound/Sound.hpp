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
	
	void PlaySound(const char *asSample);
	
	void SetMasterVolume(float afVolume);
	float GetMasterVolume() const;
	
	const char *GetSubSystemName() const {return "Sound";}
private:
	tSoundChannelVec mvChannels;
};