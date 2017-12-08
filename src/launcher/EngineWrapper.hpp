#pragma once

#include "shiftutil/SharedLib.hpp"
#include "core/ICore.hpp"

namespace rz
{
	struct ICore;
	struct TCoreInitParams; // TODO: Move inside the ICore interface (ICore::InitParams)
	struct IServiceLocator;
};

//CEngineCoreHelper
class CEngineWrapper final
{
public:
	CEngineWrapper(rz::ICore *apCore) : mpCore(apCore){}
	~CEngineWrapper(){Shutdown();}
	
	operator bool(){return mpCore != nullptr;}
	
	bool Init(const rz::TCoreInitParams &aInitParams);
	void Shutdown();
	
	void Run(); // TODO: return bool?
	//void Frame();
	
	const rz::IServiceLocator *GetEnv() const; // TODO: probably unused
private:
	rz::ICore *mpCore{nullptr};
};