#pragma once

#include "ICmdProcessor.hpp"
#include "ILog.hpp"
#include "IScheduler.hpp"

namespace rz
{

//struct ICmdProcessor;
//struct ILog;
struct IMemory;
struct IPluginManager;
struct IProfiler;
//struct IScheduler;

struct TCoreEnv
{
	ICmdProcessor *pCmdProcessor{nullptr}; // ref/GetCmdProcessor()
	ILog *pLog{nullptr}; // ref/GetLog()
	IMemory *pMemory{nullptr}; // ref/GetMemory
	IPluginManager *pPluginManager{nullptr}; // ref/GetPluginManager
	//IProfiler *pProfiler{nullptr}; // ref/GetProfiler
	IScheduler *pScheduler{nullptr}; // ref/GetScheduler
};

}; // namespace rz