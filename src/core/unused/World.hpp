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

namespace rz
{

struct IEntity;
using tEntityVec = std::vector<IEntity*>;

class CWorld
{
public:
	CWorld() = default;
	~CWorld() = default;
	
	void Update();
	
	void SetEntityActive(IEntity &aEntity, bool abActive);
private:
	tEntityVec mvEntities;
	tEntityVec mvActiveEntities;
};

}; // namespace rz