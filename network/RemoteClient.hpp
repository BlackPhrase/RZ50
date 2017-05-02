#pragma once

#include "network/IRemoteClient.hpp"

// Remote client/connection

class CRemoteClient : public IRemoteClient
{
public:
	void SetState(int anState){mnState = anState;}
	int GetState() const {return mnState;} // Will return it's current state (connecting/reconnecting/etc)
	
	void Reconnect();
	void Disconnect();
	
	bool IsConnected() const;
private:
	int mnState{0};
};