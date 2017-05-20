#pragma once

namespace rz
{

struct ILauncher
{
	virtual bool Init() = 0;
	//virtual ICore *Init() = 0;
	virtual void Shutdown() = 0;
	
	//virtual void Run(ICore *apCore) = 0;
	virtual void Frame() = 0;
};

}; // namespace rz