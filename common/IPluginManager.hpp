#pragma once

struct ISubsystem;

struct IPluginManager
{
	virtual ISubsystem *GetSubsystem(const char *asName) = 0;
};