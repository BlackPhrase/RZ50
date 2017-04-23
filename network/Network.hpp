#pragma once

#include "INetwork.hpp"

class CNetwork : public INetwork
{
public:
	CNetwork() = default;
	~CNetwork() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
};