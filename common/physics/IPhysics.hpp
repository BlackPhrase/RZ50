#pragma once

namespace rz
{

struct IPhysicsWorld;

struct IPhysics
{
	virtual IPhysicsWorld *CreateWorld() = 0;
};

}; // namespace rz