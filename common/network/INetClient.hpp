#pragma once

struct INetClient
{
	/// Tries to connect to specified hostname
	virtual bool Connect(const char *asHostName) = 0;
	
	/// Tries to reconnect to the currently connected server (if present)
	virtual bool Reconnect() = 0;
	
	/// Sends a disconnect message to server and closes the connection
	virtual void Disconnect() = 0;
	
	/// @return true if currently connected to any server
	virtual bool IsConnected() const = 0;
};