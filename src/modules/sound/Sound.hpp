/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <vector>
//#include "core/ISubSystem.hpp"
#include "sound/ISound.hpp"
#include "core/IServiceLocator.hpp"

namespace rz::sound
{

struct ISoundImpl;

class CSoundChannel;
using tSoundChannelVec = std::vector<CSoundChannel*>;

class CSound final : public ISound//, ISubSystem
{
public:
	CSound(const IServiceLocator &aCoreEnv, ISoundImpl *apImpl) : mCoreEnv(aCoreEnv), mpImpl(apImpl){}
	~CSound() = default;
	
	//bool Init(const TCoreEnv &aCoreEnv) override;
	//void Shutdown() override;
	
	//void Update() override;
	
	//ISoundChannel *CreateChannel() override;
	
	ISoundWorld &CreateWorld() override;
	void DestroyWorld(ISoundWorld &aWorld) override;
	
	void SetCurrentWorld(const ISoundWorld &aWorld) override;
	ISoundWorld *GetCurrentWorld() const override {return mpWorld;}
	
	//void SetMasterVolume(float afVolume);
	//float GetMasterVolume() const;
	
	//const char *GetSubSystemName() const override {return "Sound";}
private:
	//tSoundChannelVec mvChannels;
	
	const IServiceLocator &mCoreEnv;
	
	ISoundWorld *mpWorld{nullptr};
	
	ISoundImpl *mpImpl{nullptr};
};

}; // namespace rz::sound