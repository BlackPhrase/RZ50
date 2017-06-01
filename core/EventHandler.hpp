#pragma once

namespace rz
{

class CEventHandler final
{
public:
	CEventHandler() = default;
	~CEventHandler() = default;
	
	void Update();
	
	void Enqueue(const CEvent &aEvent);
private:
	void Poll(CEvent &aEvent);
	void Get(CEvent &aEvent);
	
	void Broadcast(const CEvent &aEvent);
};

}; // namespace rz