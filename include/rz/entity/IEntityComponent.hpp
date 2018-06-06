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

#include "IEntityEventListener.hpp"

namespace rz
{

struct IEntity;
struct TEntityEvent;

struct IEntityComponent //: public IEntityEventListener
{
	virtual ~IEntityComponent() = default;
	
	virtual void Init(){}
	virtual void Shutdown(){}
	
	virtual void OnEvent(const TEntityEvent &aEvent){}
	
	virtual const char *GetName() const = 0;
	
	virtual IEntity *GetEntity() const {return mpEntity;}
protected:
	IEntity *mpEntity{nullptr};
};

}; // namespace rz