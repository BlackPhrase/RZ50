#pragma once

#include "sound/ISoundWorld.hpp"

namespace rz
{

struct ISoundComponent;
using tSoundComponentVec = std::vector<ISoundComponent*>;

class CSoundWorld : public ISoundWorld
{
public:
	CSoundWorld() = default;
	~CSoundWorld() = default;
	
	void Update() override;
	
	void Clear();
	
	// Pass ISoundSample here?
	void PlaySound(const char *asSample, const tVec3f &avOrigin);
	
	void SetListenerPos(const tVec3f &avPos);
	const tVec3f &GetListenerPos() const;
	
	//ISoundListener *GetListener() const;
private:
	tSoundComponentVec mvSounds;
	tSoundComponentVec mvActiveSounds;
};

}; // namespace rz