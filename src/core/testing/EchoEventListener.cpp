#include "EchoEventListener.hpp"

namespace rz
{

void CEchoEventListener::OnEvent(const TEvent &aEvent)
{
	mCoreEnv.GetLog().Debug("Got an event: %s", aEvent.sName);
};

}; // namespace rz