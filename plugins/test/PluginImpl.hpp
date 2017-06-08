#pragma once

#include "core/IPlugin.hpp"

class CPluginImpl : public rz::IPlugin
{
public:
	bool Init(const rz::TCoreEnv &aCoreEnv);
	void Shutdown();
private:
	const rz::TCoreEnv *mpCoreEnv{nullptr};
};