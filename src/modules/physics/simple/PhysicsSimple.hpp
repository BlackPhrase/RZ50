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

#include "physics/IPhysics.hpp"

namespace rz
{

class CPhysics : public IPhysics
{
public:
	CPhysics() = default;
	~CPhysics() = default;
	
	void Update();
	
	const IPhysicsWorld &CreateWorld();
	
	void SetActiveWorld(const IPhysicsWorld &aWorld);
	const IPhysicsWorld &GetActiveWorld() const;
private:
	tPhysicsWorldVec mvWorlds;
};

}; // namespace rz