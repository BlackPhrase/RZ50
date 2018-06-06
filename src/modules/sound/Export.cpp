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

#include "core/CoreTypes.hpp"
#include "core/TCoreEnv.hpp"
#include "Sound.hpp"

//DECLARE_SUBSYSTEM("Sound", GetSoundSubSystem)

C_EXPORT rz::ISubSystem *GetSound(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CSound Sound(aCoreEnv);
	return &Sound;
};