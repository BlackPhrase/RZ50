#include "LoggedNetwork.hpp"
#include "Network.hpp"

//DECLARE_SUBSYSTEM(CNetwork, GetNetworkSubSystem)

#ifndef RZ_STATIC_NETWORK
	extern "C" EXPORT
#endif // RZ_STATIC_NETWORK

rz::ISubSystem *GetNetworkSubSystem()
{
	static rz::ISubSystem *pNetwork = 
	
#ifdef RZ_LOGGED_NETWORK
	new rz::CLoggedNetwork(
#endif

	new rz::CNetwork()
	
#ifdef RZ_LOGGED_NETWORK
	);
#endif
	
	return pNetwork;
};