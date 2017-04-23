#pragma once

#include "INetwork.hpp"

class CNetwork : public INetwork
{
public:
	CNetwork() = default;
	~CNetwork() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
};