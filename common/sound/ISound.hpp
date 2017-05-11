#pragma once

namespace rz
{

struct ISoundWorld;
struct ISoundChannel;

struct ISound
{
	ISoundWorld *CreateWorld() = 0;
	ISoundChannel *CreateChannel() = 0;
};

}; // namespace rz