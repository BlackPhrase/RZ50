#pragma once

#include "shiftutil/SharedLib.hpp"

namespace rz
{
	struct IEngineCore;
	struct TCoreInitParams;
};

//CEngineCoreHelper
class CEngineProxy final
{
public:
	CEngineProxy() = default;
	~CEngineProxy() = default;
	
	bool Load();
	void Unload(); // bool?
	
	bool IsLoaded() const;
	
	bool Init(const TCoreInitParams &aInitParams);
	void Shutdown();
	
	void Run();
	//void Frame();
	
	const TCoreEnv *GetEnv() const;
private:
#ifndef RZ_CORE_STATIC
	shiftutil::CSharedLib mCoreLib;
#endif

	rz::IEngineCore *mpCore{nullptr};
};