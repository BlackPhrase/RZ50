#pragma once

#include "core/IEventSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CMouseEventListener : public IEventListener
{
public:
	CMouseEventListener(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CMouseEventListener() = default;
	
	void OnEvent(const TEvent &aEvent);
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz