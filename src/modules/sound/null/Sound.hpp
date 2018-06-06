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