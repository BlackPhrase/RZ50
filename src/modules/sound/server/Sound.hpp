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