#pragma once

#include "network/IRemoteClient.hpp"

namespace rz
{

// Remote client/connection

class CRemoteClient final : public IRemoteClient
{
public:
	void SetState(int anState) override {mnState = anState;}
	int GetState() const override {return mnState;} // Will return it's current state (connecting/reconnecting/etc)
	
	void Reconnect() override;
	void Disconnect() override;
	
	bool IsConnected() const override;
private:
	int mnState{0};
};

}; // namespace rz