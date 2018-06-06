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

#include <list>
#include <map>
#include "core/CoreTypes.hpp"
#include "entity/IEntity.hpp"

namespace rz
{

struct IEntityComponent;
using tEntityComponentList = std::list<IEntityComponent*>;
using tEntityComponentMap = std::map<int, IEntityComponent*>;

struct TEntityEvent
{
	enum class Type
	{
		Invalid = -1
		Spawn,
		Destroy,
		// TODO
	};
	
	Type eType{Type::Invalid};
	
	// TODO
};

class CEntity final : public IEntity
{
public:
	CEntity(uint anID) : mnID(anID){}
	~CEntity() = default;
	
	void BroadcastEvent(const TEntityEvent &aEvent); // notify listeners (and components about the entity event)
	
	void SetName(const char *asName) override {msName = asName;}
	const char *GetName() const override {return msName.c_str();}
	
	uint GetID() const override {return mnID;}
	
	IEntityComponent *GetComponentByID(int anID) const override;
	
	template<typename T>
	inline T *GetComponent()
	{
		if(mComponentsMap.count(&typeid(T)) != 0)
			return static_cast<T*>(mComponentsMap[&typeid(T)]);
		
		return nullptr;
	};
private:
	tEntityComponentList mlstComponents;
	//tEntityComponentMap mComponentsMap; // m_mapComponents
	
	string msName{""};
	
	const uint mnID{0};
};

}; // namespace rz