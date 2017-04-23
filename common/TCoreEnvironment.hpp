#pragma once

struct ILog;
struct IPluginManager;

struct TCoreEnvironment
{
	ILog *pLog{nullptr};
	IPluginManager *pPluginManager{nullptr};
};