/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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