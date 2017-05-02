#pragma once

struct ISubSystem;

struct IPluginManager
{
	virtual ISubSystem *GetSubsystem(const char *asName) = 0;
};