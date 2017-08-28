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