#pragma once

#include "network/IRemoteClient.hpp"

namespace rz
{

// Remote client/connection

class CRemoteClient final : public IRemoteClient
{
public:
	CRemoteClient() = default;
	~CRemoteClient() = default;
	
	bool Reconnect() override;
	void Disconnect() override;
	
	void SetState(State aeState) override {meState = aeState;}
	State GetState() const override {return meState;} // Will return it's current state (connecting/reconnecting/etc)
	
	bool IsConnected() const override {return false;}
	
	//const INetAdr &GetNetAdr() const;
private:
	State meState{State::Disconnected};
};

}; // namespace rz