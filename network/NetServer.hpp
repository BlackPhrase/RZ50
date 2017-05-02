#pragma once

#include "network/INetServer.hpp"

struct IRemoteClient;
using tRemoteClientVec = std::vector<IRemoteClient*>;

class CNetServer : public INetServer
{
public:
	bool SendData(byte *apData, int anSize);
	
	IRemoteClient *GetClientById(int anID) const;
	
	void ReconnectAll();
	void DisconnectAll();
private:
	tRemoteClientVec mvClients;
};