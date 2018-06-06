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

struct ISoundChannel
{
	///
	virtual void Stop() = 0;
	
	///
	virtual void SetPause(bool abPause) = 0;
	
	///
	virtual bool IsPaused() const = 0;
	
	///
	virtual bool IsActive() const = 0; // IsPlaying
	
	///
	virtual void SetVolume(float afVolume) = 0;
	
	///
	virtual float GetVolume() const = 0;
	
	///
	virtual void SetPos(const Vec3 &avPos) = 0;
	
	///
	virtual Vec3 &GetPos() const = 0;
};

}; // namespace rz