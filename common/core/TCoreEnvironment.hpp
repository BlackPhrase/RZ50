#pragma once

namespace rz
{

struct ILog;
struct IMemory;
struct IPluginManager;
//struct IProfiler;

struct TCoreEnvironment
{
	ILog *pLog{nullptr};
	IMemory *pMemory{nullptr};
	IPluginManager *pPluginManager{nullptr};
	//IProfiler *pProfiler{nullptr};
};

}; // namespace rz