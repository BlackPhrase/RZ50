#pragma once

namespace rz
{

struct ISoundWorld;
struct ISoundChannel;

struct ISound
{
	virtual ISoundWorld *CreateWorld() = 0;
	virtual ISoundChannel *CreateChannel() = 0;
};

}; // namespace rz