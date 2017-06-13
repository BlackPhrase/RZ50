#pragma once

namespace rz
{

struct TEvent
{
	const char *sName{""};
	
	// ...
};

struct TFrameNumEvent : TEvent
{
	TFrameNumEvent()
	{
		sName = "FrameNum";
	};
	
	int nFrame{1};
};

struct IEventListener
{
	///
	virtual void OnEvent(const TEvent &aEvent) = 0;
};

struct IEventManager
{
	///
	virtual void BroadcastEvent(const TEvent &aEvent) = 0; // QueEvent
	
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