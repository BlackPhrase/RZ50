#pragma once

#include <deque>
#include <list>

namespace rz
{

struct CEvent
{
	//
};

using tEventQueue = std::deque<CEvent*>;

struct IEventListener;
using tEventListenerList = std::list<IEventListener*>;

class CEventHandler final
{
public:
	CEventHandler() = default;
	~CEventHandler() = default;
	
	void Update();
	
	void Que(const CEvent &aEvent);
private:
	CEvent *Poll();
	CEvent *Get();
	
	void Broadcast(const CEvent &aEvent);
	
	tEventQueue mEventQueue;
	
	tEventListenerList mlstListeners;
};

}; // namespace rz