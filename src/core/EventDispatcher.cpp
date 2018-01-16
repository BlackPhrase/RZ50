#include "EventDispatcher.hpp"

namespace rz
{

void CEventDispatcher::Update()
{
	DispatchEvents();
};

void CEventDispatcher::BroadcastEvent(const TEvent &aEvent)
{
	// TODO: lock or atomic?
	
	//DispatchEvent(aEvent);
	
	for(auto It : mlstListeners)
		It->OnEvent(aEvent);
};

void CEventDispatcher::QueEvent(const TEvent &aEvent)
{
	// TODO: lock or atomic
	
	// Discard the event since we have no listeners to handle it
	if(mlstListeners.empty())
		return;
	
	mEventQue.push_back(const_cast<TEvent*>(&aEvent));
};

void CEventDispatcher::DispatchEvents()
{
	// TODO: lock or atomic?
	
	if(mlstListeners.empty())
		return;
	
	auto CurrentEvent = mEventQue.front();
	
	while(!mEventQue.empty())
	{
		//mCoreEnv.pLog->Debug("Dispatching event: %s", CurrentEvent->sName);
		
		for(auto It : mlstListeners)
			It->OnEvent(*mEventQue.front());
		
		mEventQue.pop_front();
		return;
	};
	
	//mCoreEnv.pLog->Debug("Done with events");
};

// TODO: Event filters or specific event listeners/dispatchers
void CEventDispatcher::AddListener(IEventListener &aListener)
{
	// TODO: lock or atomic
	
	for(const auto It : mlstListeners)
		if(It == &aListener)
			return;

	mlstListeners.push_back(&aListener);
};

void CEventDispatcher::RemoveListener(const IEventListener &aListener)
{
	// TODO: lock or atomic
	
	for(const auto It : mlstListeners)
		if(It == &aListener)
			mlstListeners.remove(It);
};

/*
bool CEventDispatcher::Poll(TEvent &aEvent)
{
	auto It = mEventQueue.begin();
	
	if(It)
	{
		aEvent = *It;
		return true;
	};
	
	return false;
};

bool CEventDispatcher::Get(TEvent &aEvent)
{
	return false;
};
*/

}; // namespace rz