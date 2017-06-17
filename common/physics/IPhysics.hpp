#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct IPhysicsWorld;

struct IPhysics
{
	//virtual IPhysicsWorld *CreateWorld() = 0;
};

using pfnGetPhysics = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz