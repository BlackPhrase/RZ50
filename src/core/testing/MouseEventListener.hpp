#pragma once

#include "core/IEventSystem.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CMouseEventListener : public IEventListener
{
public:
	CMouseEventListener(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CMouseEventListener() = default;
	
	void OnEvent(const TEvent &aEvent);
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz