#pragma once

#include "core/IPlugin.hpp"

class CPluginImpl : public rz::IPlugin
{
public:
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
private:
	rz::TCoreEnv *mpCoreEnv{nullptr};
};