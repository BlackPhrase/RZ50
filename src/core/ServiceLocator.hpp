#pragma once

#include "core/IServiceLocator.hpp"

namespace rz
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
	const ICmdProcessor &GetCmdProcessor() const override;
	ILog &GetLog() const override;
	const IConfig &GetConfig() const override;
	const IEventDispatcher &GetEventDispatcher() const override;
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

}; // namespace rz