#include "MouseEventListener.hpp"

namespace rz
{

void CMouseEventListener::OnEvent(const TEvent &aEvent)
{
	//mCoreEnv.pLog->Debug("Got an event: %s", aEvent.sName);
	
	switch(aEvent.eType)
	{
	case TEvent::Type::MouseMove:
		auto MouseMoveEvent = static_cast<const TMouseMoveEvent*>(&aEvent);
		
		if(!MouseMoveEvent)
			return;
		
		mCoreEnv.GetLog().Debug("Got a mouse move event: %d, %d", MouseMoveEvent->nDeltaX, MouseMoveEvent->nDeltaY);
		break;
	};
};

}; // namespace rz