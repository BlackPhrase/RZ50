#pragma once

#include "core/IPlugin.hpp"

class CPluginImpl : public rz::IPlugin
{
public:
	bool Init(const rz::TCoreEnv &aCoreEnv);
	void Shutdown();
	
	int GetVersion() const {return rz::PLUGIN_INTERFACE_VERSION;}
private:
	const rz::TCoreEnv *mpCoreEnv{nullptr};
};