#pragma once

struct ISoundChannel;

struct ISound
{
	ISoundChannel *CreateChannel() = 0;
};