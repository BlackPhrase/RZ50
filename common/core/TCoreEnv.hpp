#pragma once

#include "ILog.hpp"
#include "IScheduler.hpp"

namespace rz
{

//struct ILog;
struct IMemory;
struct IPluginManager;
struct IProfiler;
//struct IScheduler;

struct TCoreEnv
{
	ILog *pLog{nullptr}; // ref/GetLog()
	IMemory *pMemory{nullptr}; // ref/GetMemory
	IPluginManager *pPluginManager{nullptr}; // ref/GetPluginManager
	//IProfiler *pProfiler{nullptr}; // ref/GetProfiler
	IScheduler *pScheduler{nullptr}; // ref/GetScheduler
};

}; // namespace rz