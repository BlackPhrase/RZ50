#pragma once

#include "ILauncher.hpp"

class CLauncher : public ILauncher
{
public:
	CLauncher() = default;
	~CLauncher() = default;
	
	ICore *Init();
	//void Shutdown();
	
	void Run(ICore *apCore);
private:
	ICore *mpCore{nullptr};
};