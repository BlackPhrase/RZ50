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

struct IEntityComponent;

struct IEntity
{
	virtual void SetName(const char *asName) = 0;
	virtual const char *GetName() const = 0;
	
	virtual IEntity *GetParent() const = 0;
	
	virtual void AddChild(const IEntity &apChild) = 0;
	virtual void RemoveChild(const IEntity &apChild) = 0;
	
	virtual IEntity *GetChild(int anIndex) const = 0;
	
	virtual void AddComponent(const IEntityComponent &apComponent, bool abAllowDups = false) = 0;
	virtual void RemoveComponent(const IEntityComponent &apComponent) = 0;
	
	virtual IEntityComponent *GetComponent(const char *asName) const = 0;
	
	/// ISoundComponent *pSoundComponent = pSomeEntity->GetComponent<ISoundComponent>();
	template<typename T>
	T *GetComponent() const;
};

}; // namespace rz