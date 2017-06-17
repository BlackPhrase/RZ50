#pragma once

namespace rz
{

struct IEntity;
struct TEntityEvent;

struct IEntityComponent
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