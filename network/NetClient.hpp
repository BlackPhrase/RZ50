#pragma once

#include "network/INetClient.hpp"

class CNetClient : public INetClient
{
public:
	bool Connect(const char *asHostName); // server hostname/ip:port
	bool Reconnect();
	void Disconnect();
	
	bool SendData(byte *apData, int anSize);
	
	bool IsConnected() const;
private:
};