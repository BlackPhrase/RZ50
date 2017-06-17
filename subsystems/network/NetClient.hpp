#pragma once

#include "network/INetClient.hpp"

namespace rz
{

class CNetClient final : public INetClient
{
public:
	CNetClient() = default;
	~CNetClient() = default;
	
	bool Connect(const char *asHostName) override; // server hostname/ip:port
	bool Reconnect() override;
	void Disconnect() override;
	
	bool SendData(byte *apData, int anSize) override;
	
	bool IsConnected() const override;
private:
};

}; // namespace rz