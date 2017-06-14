#include "NetServer.hpp"

namespace rz
{

bool CNetServer::SendData(byte *apData, int anSize)
{
	return false;
};

IRemoteClient *CNetServer::GetClientById(int anID) const
{
	if(anID < 1 || anID > mnMaxClients)
	{
		//
		return nullptr;
	};
	
	return nullptr;
};

void CNetServer::ReconnectAll()
{
};

void CNetServer::DisconnectAll()
{
};

}; // namespace rz