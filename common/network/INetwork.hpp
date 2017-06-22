#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct INetServer;
struct INetClient;

struct INetwork
{
	virtual INetServer *StartServer() = 0;
	virtual INetClient *StartClient() = 0;
};

using pfnGetNetwork = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz