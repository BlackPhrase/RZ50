#include "core/CoreTypes.hpp"
#include "Network.hpp"

//DECLARE_SUBSYSTEM(CNetwork, GetNetworkSubSystem)

C_EXPORT rz::ISubSystem *GetNetwork(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CNetwork Network(aCoreEnv);
	return &Network;
};