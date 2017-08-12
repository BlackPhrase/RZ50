#pragma once

#include "core/IEventSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CEchoEventListener : public IEventListener
{
public:
	CEchoEventListener(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CEchoEventListener() = default;
	
	void OnEvent(const TEvent &aEvent);
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz