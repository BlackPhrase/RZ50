#pragma once

#include <list>
#include <deque>
#include "core/IEventSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

using tEventListenerList = std::list<IEventListener*>;

//tEventQue
using tEventDeque = std::deque<TEvent*>;

//CEventHandler
class CEventManager final : public IEventManager
{
public:
	CEventManager(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CEventManager() = default;
	
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
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz