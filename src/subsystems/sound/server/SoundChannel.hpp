#pragma once

#include "sound/ISoundChannel.hpp"

class CSoundChannel : public ISoundChannel
{
public:
	void Play(const char *asSample);
	void Stop();
	
	void Update();
	
	void SetPause(bool abPause);
	bool IsPaused() const;
private:
};