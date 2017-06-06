#include "EventHandler.hpp"

namespace rz
{

void CEventHandler::Update()
{
	CEvent Event;
	
	while(Poll(Event)) // HasEvents
		Broadcast(Event);
};

void CEventHandler::Que(const CEvent &aEvent)
{
	mEventQueue.push_back(aEvent);
};

bool CEventHandler::Poll(CEvent &aEvent)
{
	auto It = mEventQueue.begin();
	
	if(It)
	{
		aEvent = *It;
		return true;
	};
	
	return false;
};

void CEventHandler::Get(CEvent &aEvent)
{
};

void CEventHandler::Broadcast(const CEvent &aEvent)
{
	for(auto It : mlstListeners)
		It->OnEvent(aEvent);
};

}; // namespace rz