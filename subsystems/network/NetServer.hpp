#pragma once

#include <vector>
#include "network/INetServer.hpp"

namespace rz
{

struct IRemoteClient;
using tRemoteClientVec = std::vector<IRemoteClient*>;

class CNetServer final : public INetServer
{
public:
	CNetServer() = default;
	~CNetServer() = default;
	
	bool SendData(byte *apData, int anSize) override;
	
	IRemoteClient *GetClientById(int anID) const override;
	
	void ReconnectAll() override;
	void DisconnectAll() override;
private:
	tRemoteClientVec mvClients;
	
	uint mnMaxClients{0};
};

}; // namespace rz