#pragma once

namespace rz
{

struct TEntityEvent;

struct IEntityEventListener
{
	virtual void OnEvent(const TEntityEvent &aEvent) = 0;
};

}; // namespace rz