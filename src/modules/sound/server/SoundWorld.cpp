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

#include "SoundWorld.hpp"

namespace rz
{

void CSoundWorld::Update()
{
	for(auto It : mvActiveSounds)
		It->Update();
};

void CSoundWorld::Clear()
{
};

void CSoundWorld::BroadcastSound(const Vec3f &aPos, const char *asSample)
{
	TSoundNetMsg SoundBroadcast(aPos, asSample);
	mpServer->BroadcastMsg(TSoundNetMsg);
};

}; // namespace rz