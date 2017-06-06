#pragma once

#include <vector>
#include "core/ISubSystem.hpp"
#include "sound/ISound.hpp"

namespace rz
{

using tSoundChannelVec = std::vector<ISoundChannel*>;

class CSound : public ISubSystem, ISound
{
public:
	CSound() = default;
	~CSound() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	ISoundChannel *CreateChannel();
	
	ISoundWorld *CreateWorld();
	
	void PlaySound(const char *asSample);
	
	void SetMasterVolume(float afVolume);
	float GetMasterVolume() const;
	
	const char *GetSubSystemName() const {return "Sound";}
private:
	tSoundChannelVec mvChannels;
};

}; // namespace rz