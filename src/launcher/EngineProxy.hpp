#pragma once

#include "shiftutil/SharedLib.hpp"
#include "core/ICore.hpp"

namespace rz
{
	struct ICore;
	struct TCoreInitParams;
	struct TCoreEnv;
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
	
	bool Init(const rz::TCoreInitParams &aInitParams);
	void Shutdown();
	
	void Run();
	//void Frame();
	
	const rz::TCoreEnv *GetEnv() const;
private:
#ifndef RZ_CORE_STATIC
	shiftutil::CSharedLib mCoreLib;
#endif

	rz::ICore *mpCore{nullptr};
};