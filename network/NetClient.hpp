#pragma once

#include "network/INetClient.hpp"

class CNetClient final : public INetClient
{
public:
	bool Connect(const char *asHostName) override; // server hostname/ip:port
	bool Reconnect() override;
	void Disconnect() override;
	
	bool SendData(byte *apData, int anSize) override;
	
	bool IsConnected() const override;
private:
};