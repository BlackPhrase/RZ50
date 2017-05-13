#pragma once

#include "network/INetServer.hpp"

namespace rz
{

struct IRemoteClient;
using tRemoteClientVec = std::vector<IRemoteClient*>;

class CNetServer final : public INetServer
{
public:
	bool SendData(byte *apData, int anSize) override;
	
	IRemoteClient *GetClientById(int anID) const override;
	
	void ReconnectAll() override;
	void DisconnectAll() override;
private:
	tRemoteClientVec mvClients;
};

}; // namespace rz