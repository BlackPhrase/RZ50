#pragma once

namespace rz
{

struct TEvent
{
	// ...
};

struct IEventListener
{
	///
	virtual void OnEvent(const TEvent &aEvent) = 0;
};

struct IEventManager
{
	///
	virtual void BroadcastEvent(const TEvent &aEvent) = 0;
	
	///
	virtual void AddListener(const IEventListener &aListener) = 0;
	
	///
	virtual void RemoveListener(const IEventListener &aListener) = 0;
	
	///
	//virtual void PollEvent(TEvent &aEvent) = 0;
	
	///
	//virtual void GetEvent(TEvent &aEvent) = 0;
};

}; // namespace rz