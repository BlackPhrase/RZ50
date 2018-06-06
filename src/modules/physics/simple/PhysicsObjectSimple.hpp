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

class CPhysicsObject
{
public:
	CPhysicsObject() = default;
	~CPhysicsObject() = default;
	
	void Update(float afDeltaTime); // Integrate
	
	void SetPos(const CVec3f &avPos){mvPosition = avPos;}
	const CVec3f &GetPos() const {return mvPosition;}
	
	void SetVelocity(const CVec3f &avVelocity){mvVelocity = avVelocity;}
	const CVec3f &GetVelocity() const {return mvVelocity;}
private:
	CVec3f mvPosition{0.0f, 0.0f, 0.0f};
	CVec3f mvVelocity{0.0f, 0.0f, 0.0f};
};

}; // namespace rz