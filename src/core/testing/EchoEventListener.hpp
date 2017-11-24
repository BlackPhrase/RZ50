#pragma once

#include "core/IEventSystem.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CEchoEventListener : public IEventListener
{
public:
	CEchoEventListener(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CEchoEventListener() = default;
	
	void OnEvent(const TEvent &aEvent);
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz