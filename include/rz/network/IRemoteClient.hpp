#pragma once

namespace rz
{

struct IRemoteClient
{
	enum class State : int
	{
		Disconnected = 0, ///< Disconnect and not active
		Connected = 1,    ///< Connected
		Connecting,       ///< Currently connecting or reconnecting
		Disconnecting     ///< Disconnecting
	};
	
	/// Tries to reconnect to the currently connected server (if present)
	virtual bool Reconnect() = 0;
	
	/// Sends a disconnect message to server and closes the connection
	virtual void Disconnect() = 0;
	
	///
	virtual void SetState(State anState) = 0;
	
	///
	virtual State GetState() const = 0;
	
	/// @return true if currently connected to any server
	virtual bool IsConnected() const = 0;
};

}; // namespace rz