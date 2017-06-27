#pragma once

namespace rz
{

struct ISoundChannel
{
	///
	virtual void Stop() = 0;
	
	///
	virtual void SetPause(bool abPause) = 0;
	
	///
	virtual bool IsPaused() const = 0;
	
	///
	virtual bool IsActive() const = 0; // IsPlaying
	
	///
	virtual void SetVolume(float afVolume) = 0;
	
	///
	virtual float GetVolume() const = 0;
	
	///
	virtual void SetPos(const Vec3 &avPos) = 0;
	
	///
	virtual Vec3 &GetPos() const = 0;
};

}; // namespace rz