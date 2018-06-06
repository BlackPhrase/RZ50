/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "ICmdProcessor.hpp"
#include "ILog.hpp"
#include "IConfig.hpp"
#include "IMemory.hpp"
#include "IPluginManager.hpp"
#include "IEventSystem.hpp"
#include "IScheduler.hpp"
#include "IModuleContainer.hpp"

namespace rz
{

//struct ICmdProcessor;
//struct ILog;
//struct IConfig;
//struct IMemory;
//struct IPluginManager;
//struct IProfiler;
//struct IScheduler;

/// Core environment
struct IServiceLocator
{
	///
	//virtual void ProvideFileSystem(IFileSystem &aFileSystem) = 0;
	
	///
	virtual void ProvideCmdProcessor(ICmdProcessor &aCmdProcessor) = 0;
	
	///
	virtual void ProvideLog(ILog &aLog) = 0;
	
	///
	virtual void ProvideConfig(IConfig &aConfig) = 0;
	
	///
	virtual void ProvideEventDispatcher(IEventDispatcher &aEventDispatcher) = 0;
	
	///
	virtual void ProvideMemory(IMemory &aMemory) = 0;
	
	///
	virtual void ProvidePluginManager(IPluginManager &aPluginManager) = 0;
	
	///
	//virtual void ProvideProfiler(IProfiler &aProfiler) = 0;
	
	///
	virtual void ProvideScheduler(IScheduler &aScheduler) = 0;
	
	///
	virtual void ProvideModuleContainer(IModuleContainer &aModuleContainer) = 0;
	
	///
	//virtual const IFileSystem &GetFileSystem() const = 0;
	
	/// Command processor
	virtual ICmdProcessor &GetCmdProcessor() const = 0;
	
	/// Direct logging functionality
	virtual ILog &GetLog() const = 0;
	
	/// Configuration settings
	virtual const IConfig &GetConfig() const = 0;
	
	/// Event manager
	virtual IEventDispatcher &GetEventDispatcher() const = 0;
	
	/// Memory manager
	virtual const IMemory &GetMemory() const = 0;
	
	/// Plugin manager
	virtual const IPluginManager &GetPluginManager() const = 0;
	
	/// Profiler
	//virtual const IProfiler &GetProfiler() const = 0;
	
	/// Scheduler
	virtual const IScheduler &GetScheduler() const = 0;
	
	/// Sub-system manager
	virtual const IModuleContainer &GetModuleContainer() const = 0;
};

}; // namespace rz