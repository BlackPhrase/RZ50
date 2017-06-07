#include "EventHandler.hpp"

namespace rz
{

void CEventHandler::Update()
{
	CEvent *pEvent = nullptr;
	
	//while(pEvent = Poll()) // HasEvents
		//Broadcast(Event);
};

void CEventHandler::Que(const CEvent &aEvent)
{
	//mEventQueue.push_back(aEvent);
};

CEvent *CEventHandler::Poll()
{
	auto It = mEventQueue.begin();
	
	//if(It)
	{
		//aEvent = *It;
		return *It;
	};
	
	return nullptr;
};

CEvent *CEventHandler::Get()
{
	return nullptr;
};

void CEventHandler::Broadcast(const CEvent &aEvent)
{
	//for(auto It : mlstListeners)
		//It->OnEvent(aEvent);
};

}; // namespace rz