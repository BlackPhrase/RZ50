#pragma once

#include "ISystem.hpp"

class CSystem : public ISystem
{
public:
	CSystem() = default;
	~CSystem() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
};