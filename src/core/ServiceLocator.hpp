/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "core/IServiceLocator.hpp"

namespace rz::core
{

class CServiceLocator final : public IServiceLocator
{
public:
	CServiceLocator();
	~CServiceLocator();
	
	//void ProvideFileSystem(IFileSystem &aFileSystem) override;
	void ProvideCmdProcessor(ICmdProcessor &aCmdProcessor) override;
	void ProvideLog(ILog &aLog) override;
	void ProvideConfig(IConfig &aConfig) override;
	void ProvideEventDispatcher(IEventDispatcher &aEventDispatcher) override;
	void ProvideMemory(IMemory &aMemory) override;
	void ProvidePluginManager(IPluginManager &aPluginManager) override;
	//void ProvideProfiler(IProfiler &aProfiler) override;
	void ProvideScheduler(IScheduler &aScheduler) override;
	void ProvideModuleContainer(IModuleContainer &aModuleContainer) override;
	
	//const IFileSystem &GetFileSystem() const override;
	ICmdProcessor &GetCmdProcessor() const override;
	ILog &GetLog() const override;
	const IConfig &GetConfig() const override;
	IEventDispatcher &GetEventDispatcher() const override;
	const IMemory &GetMemory() const override;
	const IPluginManager &GetPluginManager() const override;
	//const IProfiler &GetProfiler() const override;
	const IScheduler &GetScheduler() const override;
	const IModuleContainer &GetModuleContainer() const override;
private:
	//IFileSystem *mpFileSystem{nullptr};
	ICmdProcessor *mpCmdProcessor{nullptr};
	ILog *mpLog{nullptr};
	IConfig *mpConfig{nullptr};
	IEventDispatcher *mpEventDispatcher{nullptr};
	IMemory *mpMemory{nullptr};
	IPluginManager *mpPluginManager{nullptr};
	//IProfiler *mpProfiler{nullptr};
	IScheduler *mpScheduler{nullptr};
	IModuleContainer *mpModuleContainer{nullptr};
};

}; // namespace rz::core