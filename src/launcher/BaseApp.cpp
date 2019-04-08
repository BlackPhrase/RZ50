#include "BaseApp.hpp"

CBaseApp::CBaseApp() = default;
CBaseApp::~CBaseApp() = default;

void CBaseApp::Run()
{
	if(!Init())
		return;
	
	mbRunning = true;
	
	while(mbRunning)
	{
		// TODO: update window
		
		if(!mbPaused)
			RunFrame();
	};
	
	Shutdown();
};

void CBaseApp::OnEvent(const graphics::IWindow::Event &aEvent)
{
	switch(aEvent.meType)
	{
	case graphics::IWindow::Event::Type::Close:
		mbRunning = false;
		break;
	case graphics::IWindow::Event::Type::Activate: // StateChange?
		(aEvent.state.current == IWindow::State::Active) ? mbPaused = false : mbPaused = true;
		break;
	case graphics::IWindow::Event::Type::BeginResize:
		mbPaused = true;
		break;
	case graphics::IWindow::Event::Type::EndResize:
		mbPaused = false;
		break;
	};
};

bool CBaseApp::Init()
{
	if(!PreInit())
		return false;
	
	// Actually init
	// TODO: attach event listener to window
	
	PostInit();
	return true;
};

void CBaseApp::Shutdown()
{
};