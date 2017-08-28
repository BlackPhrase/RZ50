#pragma once

namespace rz
{

struct IGameObject
{
	virtual bool AddComponent() = 0;
	virtual void RemoveComponent() = 0;
	virtual void *GetComponent() = 0;
};

}; // namespace rz