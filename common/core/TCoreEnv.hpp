#pragma once

#include "ICmdProcessor.hpp"
#include "ILog.hpp"
#include "IConfig.hpp"
#include "IEventSystem.hpp"
#include "IScheduler.hpp"

namespace rz
{

//struct ICmdProcessor;
//struct ILog;
//struct IConfig;
struct IMemory;
struct IPluginManager;
struct IProfiler;
//struct IScheduler;

/// Core environment
struct TCoreEnv
{
	/// Command processor
	ICmdProcessor *pCmdProcessor{nullptr}; // ref/GetCmdProcessor()
	
	/// Direct logging functionality
	ILog *pLog{nullptr}; // ref/GetLog()
	
	/// Configuration settings
	IConfig *pConfig{nullptr}; // ref/GetConfig()
	
	/// Event manager
	IEventManager *pEventManager{nullptr}; // ref/GetEventManager()
	
	/// Memory manager
	IMemory *pMemory{nullptr}; // ref/GetMemory
	
	/// Plugin manager
	IPluginManager *pPluginManager{nullptr}; // ref/GetPluginManager
	
	/// Profiler
	//IProfiler *pProfiler{nullptr}; // ref/GetProfiler
	
	/// Scheduler
	IScheduler *pScheduler{nullptr}; // ref/GetScheduler
};

}; // namespace rz