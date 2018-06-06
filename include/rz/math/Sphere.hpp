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

#include "Vec3.hpp"

namespace rz
{

struct TSphere
{
	TSphere() = default;
	TSphere(const TVec3 &avCenter, float afRadius) : vCenter(avCenter), fRadius(afRadius){}
	
	TVec3 vCenter{0.0f, 0.0f, 0.0f};
	float fRadius{0.0f};
};

}; // namespace rz