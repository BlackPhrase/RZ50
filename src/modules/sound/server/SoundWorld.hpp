#pragma once

#include "sound/ISoundWorld.hpp"

namespace rz
{

struct TSoundComponent; // CSoundEntity?
using tSoundComponentVec = std::vector<TSoundComponent*>;

class CSoundWorld : public ISoundWorld
{
public:
	CSoundWorld() = default;
	~CSoundWorld() = default;
	
	void Update();
	
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