#pragma once

#include <list>
#include <deque>
#include "core/IEventSystem.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

using tEventListenerList = std::list<IEventListener*>;

//tEventQue
using tEventDeque = std::deque<TEvent*>;

//CEventHandler
class CEventDispatcher final : public IEventDispatcher
{
public:
	CEventDispatcher(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CEventDispatcher() = default;
	
	void Update(); // TODO: updateable component interface
	
	void BroadcastEvent(const TEvent &aEvent) override;
	void QueEvent(const TEvent &aEvent) override;
	
	void DispatchEvents();
	
	void AddListener(const IEventListener &aListener) override;
	void RemoveListener(const IEventListener &aListener) override;
private:
	//bool Poll(TEvent &aEvent);
	//bool Get(TEvent &aEvent);
	
	tEventListenerList mlstListeners;
	tEventDeque mEventQue;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz