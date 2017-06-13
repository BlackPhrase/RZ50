#include "EventManager.hpp"

namespace rz
{

void CEventManager::Update()
{
	DispatchEvents();
};

void CEventManager::BroadcastEvent(const TEvent &aEvent)
{
	mEventQue.push_back(const_cast<TEvent*>(&aEvent));
};

void CEventManager::DispatchEvents()
{
	auto CurrentEvent = mEventQue.front();
	
	//if(mlstListeners.empty())
		//return;
	
	while(!mEventQue.empty())
	{
		//mCoreEnv.pLog->Debug("Dispatching event: %s", CurrentEvent->sName);
		
		for(auto It : mlstListeners)
			It->OnEvent(*mEventQue.front());
		
		mEventQue.pop_front();
		return;
	};
	
	mCoreEnv.pLog->Debug("Done with events");
};

void CEventManager::AddListener(const IEventListener &aListener)
{
	for(const auto It : mlstListeners)
		if(It == &aListener)
			return;

	mlstListeners.push_back((IEventListener*)&aListener);
};

void CEventManager::RemoveListener(const IEventListener &aListener)
{
	for(const auto It : mlstListeners)
		if(It == &aListener)
			mlstListeners.remove(It);
};

}; // namespace rz