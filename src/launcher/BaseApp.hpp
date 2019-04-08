#pragma once

#include "graphics/IWindow.hpp"

class CBaseApp : public IWindow::EventListener
{
public:
	CBaseApp();
	~CBaseApp();
	
	void Run();
	
	void OnEvent(const graphics::IWindow::Event &aEvent) override;
private:
	bool Init();
	void Shutdown();
	
	graphics::IWindow 
	
	bool mbRunning{false};
	bool mbPaused{false};
protected:
	bool PreInit(){}
	void PostInit(){}
};