#include "Graphics.hpp"
#include "IGraphicsImpl.hpp"

namespace rz
{

bool CGraphics::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("Graphics");
	
	if(!OpenWindow())
	{
		mpCoreEnv->pLog->Error("Failed to open the rendering window!");
		return false;
	};
	
	mpCoreEnv->pEventManager->AddListener(*this);
	return mpImpl->Init(aCoreEnv);
};

void CGraphics::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("Graphics");
	
	// BUG: this line is causing the window to freeze
	//mpCoreEnv->pEventManager->RemoveListener(*this); // event manager will free all its listeners at shutdown
};

void CGraphics::Update()
{
};

void CGraphics::OnEvent(const TEvent &aEvent)
{
	switch(aEvent.eType)
	{
	case TEvent::Type::FrameBegin:
		ProcessEvents();
		break;
	};
};

bool CGraphics::OpenWindow()
{
	mpCoreEnv->pLog->Debug("Opening a rendering window...");
	return mpImpl->OpenWindow();
};

void CGraphics::ProcessEvents()
{
	mpImpl->ProcessEvents();
};

}; // namespace rz