#include "EventManager.hpp"

namespace rz
{

void CEventManager::Update()
{
	DispatchEvents();
};

void CEventManager::BroadcastEvent(const TEvent &aEvent)
{
	// TODO: lock or atomic?
	
	//DispatchEvent(aEvent);
	
	for(auto It : mlstListeners)
		It->OnEvent(aEvent);
};

void CEventManager::QueEvent(const TEvent &aEvent)
{
	// TODO: lock or atomic
	
	// Discard the event since we have no listeners to handle it
	if(mlstListeners.empty())
		return;
	
	mEventQue.push_back(const_cast<TEvent*>(&aEvent));
};

void CEventManager::DispatchEvents()
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
void CEventManager::AddListener(const IEventListener &aListener)
{
	// TODO: lock or atomic
	
	for(const auto It : mlstListeners)
		if(It == &aListener)
			return;

	mlstListeners.push_back((IEventListener*)&aListener);
};

void CEventManager::RemoveListener(const IEventListener &aListener)
{
	// TODO: lock or atomic
	
	for(const auto It : mlstListeners)
		if(It == &aListener)
			mlstListeners.remove(It);
};

}; // namespace rz