#pragma once

namespace rz
{

struct ILog;
struct IMemory;
struct IPluginManager;

struct TCoreEnvironment
{
	ILog *pLog{nullptr};
	IMemory *pMemory{nullptr};
	IPluginManager *pPluginManager{nullptr};
};

}; // namespace rz