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

#include "ServiceLocator.hpp"

namespace rz
{

CServiceLocator::CServiceLocator() = default;
CServiceLocator::~CServiceLocator() = default;

//void CServiceLocator::ProvideFileSystem(IFileSystem &aFileSystem)
//{
	//mpFileSystem = std::addressof(aFileSystem);
//};

void CServiceLocator::ProvideCmdProcessor(ICmdProcessor &aCmdProcessor)
{
	mpCmdProcessor = std::addressof(aCmdProcessor);
};

void CServiceLocator::ProvideLog(ILog &aLog)
{
	mpLog = std::addressof(aLog);
};

void CServiceLocator::ProvideConfig(IConfig &aConfig)
{
	mpConfig = std::addressof(aConfig);
};

void CServiceLocator::ProvideEventDispatcher(IEventDispatcher &aEventDispatcher)
{
	mpEventDispatcher = std::addressof(aEventDispatcher);
};

void CServiceLocator::ProvideMemory(IMemory &aMemory)
{
	mpMemory = std::addressof(aMemory);
};

void CServiceLocator::ProvidePluginManager(IPluginManager &aPluginManager)
{
	mpPluginManager = std::addressof(aPluginManager);
};

//void CServiceLocator::ProvideProfiler(IProfiler &aProfiler)
//{
	//mpProfiler = std::addressof(aProfiler);
//};

void CServiceLocator::ProvideScheduler(IScheduler &aScheduler)
{
	mpScheduler = std::addressof(aScheduler);
};

void CServiceLocator::ProvideModuleContainer(IModuleContainer &aModuleContainer)
{
	mpModuleContainer = std::addressof(aModuleContainer);
};

//const IFileSystem &CServiceLocator::GetFileSystem() const
//{
	//return *mpFileSystem;
//};

ICmdProcessor &CServiceLocator::GetCmdProcessor() const
{
	return *mpCmdProcessor;
};

ILog &CServiceLocator::GetLog() const
{
	return *mpLog;
};

const IConfig &CServiceLocator::GetConfig() const
{
	return *mpConfig;
};

IEventDispatcher &CServiceLocator::GetEventDispatcher() const
{
	return *mpEventDispatcher;
};

const IMemory &CServiceLocator::GetMemory() const
{
	return *mpMemory;
};

const IPluginManager &CServiceLocator::GetPluginManager() const
{
	return *mpPluginManager;
};

//const IProfiler &CServiceLocator::GetProfiler() const
//{
	//return *mpProfiler;
//};

const IScheduler &CServiceLocator::GetScheduler() const
{
	return *mpScheduler;
};

const IModuleContainer &CServiceLocator::GetModuleContainer() const
{
	return *mpModuleContainer;
};

}; // namespace rz