#pragma once

#include <vector>
#include "core/ISubSystem.hpp"
#include "sound/ISound.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

using tSoundChannelVec = std::vector<ISoundChannel*>;

class CSound final : public ISubSystem, ISound
{
public:
	CSound(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CSound() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	//ISoundChannel *CreateChannel();
	
	//ISoundWorld *CreateWorld();
	
	//void PlaySound(const char *asSample);
	
	//void SetMasterVolume(float afVolume);
	//float GetMasterVolume() const;
	
	const char *GetSubSystemName() const override {return "Sound";}
private:
	//tSoundChannelVec mvChannels;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz