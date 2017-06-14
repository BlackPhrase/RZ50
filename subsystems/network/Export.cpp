#include "core/CoreTypes.hpp"
#include "Network.hpp"

//DECLARE_SUBSYSTEM(CNetwork, GetNetworkSubSystem)

C_EXPORT rz::ISubSystem *GetNetwork()
{
	static rz::CNetwork Network;
	return &Network;
};