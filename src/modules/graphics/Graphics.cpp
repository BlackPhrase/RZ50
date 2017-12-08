#include "Graphics.hpp"
#include "IGraphicsImpl.hpp"
#include "IRender.hpp"

namespace rz
{

bool CGraphics::Init(const IServiceLocator &aCoreEnv)
{
	mCoreEnv.GetLog().TraceInit("Graphics");
	mCoreEnv.GetLog().Info("Graphics: Null");
	
	if(!OpenWindow())
	{
		mCoreEnv.GetLog().Error("Failed to open the rendering window!");
		return false;
	};
	
	mCoreEnv.pEventManager->AddListener(*this);
	
	// TODO: pass a window interface?
	//if(!mpRender->Init(0, 0, 1280, 600))
		//return false;
	
	return mpImpl->Init(aCoreEnv);
};

void CGraphics::Shutdown()
{
	mpRender->Shutdown();
	
	// BUG: this line is causing the window to freeze
	//mCoreEnv.pEventManager->RemoveListener(*this); // event manager will free all its listeners at shutdown
};

void CGraphics::Update()
{
};

void CGraphics::OnEvent(const TEvent &aEvent)
{
	switch(aEvent.eType)
	{
	case TEvent::Type::FrameBegin: // NOTE: start of the whole frame, not rendering
		ProcessEvents();
		mpRender->FrameBegin();
		break;
	case TEvent::Type::FrameEnd: // NOTE: end of the whole frame, not rendering
		mpRender->FrameEnd();
		break;
	};
};

bool CGraphics::OpenWindow()
{
	mCoreEnv.GetLog().Debug("Opening a rendering window...");
	return mpImpl->OpenWindow(mCoreEnv.pConfig->GetInt("Graphics:WindowWidth", 1280), mCoreEnv.pConfig->GetInt("Graphics:WindowHeight", 600));
};

void CGraphics::ProcessEvents()
{
	mpImpl->ProcessEvents();
};

}; // namespace rz