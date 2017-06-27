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

class CEntity final : public IEntity
{
public:
	CEntity(uint anID) : mnID(anID){}
	~CEntity() = default;
	
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