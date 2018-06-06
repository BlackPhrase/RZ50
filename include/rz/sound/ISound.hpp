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

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct ISoundWorld;
struct ISoundChannel;

struct ISound
{
	virtual const ISoundWorld &CreateWorld() = 0;
	virtual void DestroyWorld(ISoundWorld &aWorld) = 0;
	
	// SetActiveWorld
	virtual void SetCurrentWorld(const ISoundWorld &aWorld) = 0;
	virtual ISoundWorld *GetCurrentWorld() const = 0;
	
	//virtual ISoundChannel *CreateChannel() = 0;
};

using pfnGetSound = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz