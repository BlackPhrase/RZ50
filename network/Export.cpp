#include "LoggedNetwork.hpp"
#include "Network.hpp"

//DECLARE_SUBSYSTEM(CNetwork, GetNetworkSubSystem)

#ifndef RZ_STATIC_NETWORK
	extern "C" EXPORT
#endif // RZ_STATIC_NETWORK

ISubSystem *GetNetworkSubSystem()
{
	static ISubSystem *pNetwork = 
	
#ifdef RZ_LOGGED_NETWORK
	new CLoggedNetwork(
#endif

	new CNetwork()
	
#ifdef RZ_LOGGED_NETWORK
	);
#endif
	
	return pNetwork;
};