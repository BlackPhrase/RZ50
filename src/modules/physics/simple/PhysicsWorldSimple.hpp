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

#include "physics/IPhysicsWorld.hpp"

namespace rz
{

class CPhysicsObject;

// Simple Physics World Implementation
class CPhysicsWorld : public IPhysicsWorld
{
public:
	CPhysicsWorld() = default;
	~CPhysicsWorld() = default;
	
	void Update();
	
	void Simulate(float afDeltaTime);
	
	void AddObject(const CPhysicsObject &aObject);
	
	void SetGravity(const CVec3f &avGravity){mvGravity = avGravity;}
	const CVec3f &GetGravity() const {return mvGravity;}
private:
	tPhysicsObjectVec mvObjects;
	
	CVec3f mvGravity{0.0f, 0.0f, 0.0f};
};

}; // namespace rz