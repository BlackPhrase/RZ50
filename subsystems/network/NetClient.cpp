#include "NetClient.hpp"

namespace rz
{

bool CNetClient::Connect()
{
	return true;
};

bool CNetClient::Reconnect()
{
	return true;
};

void CNetClient::Disconnect()
{
};

bool CNetClient::SendData(byte *apData, int anSize)
{
	return false;
};
	
bool CNetClient::IsConnected() const
{
	return false;
};

}; // namespace rz