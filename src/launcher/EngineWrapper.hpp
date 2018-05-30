/// @file
/// @brief engine module wrapper

#pragma once

#include "shiftutil/shared_lib.hpp"
#include "core/ICore.hpp"

namespace rz
{
	struct ICore;
	struct IServiceLocator;
};

//CEngineCoreWrapper
class CEngineWrapper final
{
public:
	CEngineWrapper(rz::ICore *apCore) : mpCore(apCore){}
	~CEngineWrapper(){Shutdown();}
	
	operator bool(){return mpCore != nullptr;}
	
	bool Init(const rz::ICore::TInitParams &aInitParams);
	void Shutdown();
	
	void Run(); // TODO: return bool?
	//void Frame();
	
	const rz::IServiceLocator *GetEnv() const; // TODO: probably unused
private:
	rz::ICore *mpCore{nullptr};
};