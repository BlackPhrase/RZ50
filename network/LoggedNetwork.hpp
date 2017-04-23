#pragma once

#include "INetwork.hpp"

class CLoggedNetwork : public INetwork
{
public:
	CLoggedNetwork(const INetwork &aImpl) : mpImpl(*aImpl){}
	~CLoggedNetwork() = default;
	
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	void Update();
private:
	INetwork *mpImpl{nullptr};
};