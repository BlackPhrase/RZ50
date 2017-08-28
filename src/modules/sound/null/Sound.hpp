#pragma once

#include <vector>
#include "sound/ISound.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

using tSoundChannelVec = std::vector<ISoundChannel*>;

class CSound final : public ISound
{
public:
	CSound(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CSound() = default;
	
	//ISoundChannel *CreateChannel() override;
	
	const ISoundWorld &CreateWorld() override;
	void DestroyWorld(ISoundWorld &aWorld) override;
	
	void SetCurrentWorld(const ISoundWorld &aWorld) override;
	ISoundWorld *GetCurrentWorld() const override {return mpWorld;}
	
	//void SetMasterVolume(float afVolume);
	//float GetMasterVolume() const;
private:
	//tSoundChannelVec mvChannels;
	
	const TCoreEnv &mCoreEnv;
	
	ISoundWorld *mpWorld{nullptr};
};

}; // namespace rz