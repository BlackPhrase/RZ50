#pragma once

#include "ILauncher.hpp"

class CLauncher : public ILauncher
{
public:
	CLauncher() = default;
	~CLauncher() = default;
	
	ICore *Init(); // core will be initialized already by the time it's returned
	//void Shutdown();
	
	void Run(const ICore &apCore); // after all the core post-init routines you can run it
private:
	ICore *mpCore{nullptr};
};