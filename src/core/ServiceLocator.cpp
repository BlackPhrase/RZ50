#include "ServiceLocator.hpp"

namespace rz
{

CServiceLocator::CServiceLocator() = default;
CServiceLocator::~CServiceLocator() = default;

//void CServiceLocator::ProvideFileSystem(IFileSystem &aFileSystem)
//{
	//*mpFileSystem = aFileSystem;
//};

void CServiceLocator::ProvideCmdProcessor(ICmdProcessor &aCmdProcessor)
{
	*mpCmdProcessor = aCmdProcessor;
};

void CServiceLocator::ProvideLog(ILog &aLog)
{
	*mpLog = aLog;
};

void CServiceLocator::ProvideConfig(IConfig &aConfig)
{
	*mpConfig = aConfig;
};

void CServiceLocator::ProvideEventDispatcher(IEventDispatcher &aEventDispatcher)
{
	*mpEventDispatcher = aEventDispatcher;
};

void CServiceLocator::ProvideMemory(IMemory &aMemory)
{
	*mpMemory = aMemory;
};

void CServiceLocator::ProvidePluginManager(IPluginManager &aPluginManager)
{
	*mpPluginManager = aPluginManager;
};

//void CServiceLocator::ProvideProfiler(IProfiler &aProfiler)
//{
	//*mpProfiler = aProfiler;
//};

void CServiceLocator::ProvideScheduler(IScheduler &aScheduler)
{
	*mpScheduler = aScheduler;
};

void CServiceLocator::ProvideModuleContainer(IModuleContainer &aModuleContainer)
{
	*mpModuleContainer = aModuleContainer;
};

//const IFileSystem &CServiceLocator::GetFileSystem() const
//{
	//return *mpFileSystem;
//};

const ICmdProcessor &CServiceLocator::GetCmdProcessor() const
{
	return *mpCmdProcessor;
};

const ILog &CServiceLocator::GetLog() const
{
	return *mpLog;
};

const IConfig &CServiceLocator::GetConfig() const
{
	return *mpConfig;
};

const IEventDispatcher &CServiceLocator::GetEventDispatcher() const
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