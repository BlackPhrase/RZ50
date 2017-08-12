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
	
	return mvClients[anID - 1]; // Hmm...
};

void CNetServer::ReconnectAll()
{
	for(auto It : mvClients)
		It->Reconnect();
};

void CNetServer::DisconnectAll()
{
	for(auto It : mvClients)
		It->Disconnect();
};

}; // namespace rz