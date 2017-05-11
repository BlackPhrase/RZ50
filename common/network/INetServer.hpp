#pragma once

namespace rz
{

struct IRemoteClient;

struct INetServer
{
	/// Tries to get a client by it's id
	/// @return nullptr if not found
	virtual IRemoteClient *GetClientById(int anID) = 0;
	
	/// Causes any connected client to be reconnected
	virtual void ReconnectAll() = 0; // BroadcastReconnect
	
	/// Causes any connected client to be disconnected
	virtual void DisconnectAll() = 0; // BroadcastDisconnect
};

}; // namespace rz