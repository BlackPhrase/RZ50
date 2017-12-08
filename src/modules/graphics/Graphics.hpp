#pragma once

#include "graphics/IGraphics.hpp"
#include "core/IServiceLocator.hpp"
#include "core/IEventSystem.hpp"

namespace rz
{

struct IGraphicsImpl;
struct IRender;

class CGraphics final : public IGraphics, IEventListener
{
public:
	CGraphics(const IServiceLocator &aCoreEnv, IGraphicsImpl *apImpl, IRender *apRender)
		: mCoreEnv(aCoreEnv), mpImpl(apImpl), mpRender(apRender){}
	~CGraphics() = default;
	
	bool Init(const IServiceLocator &aCoreEnv); //override;
	void Shutdown(); //override;
	
	void Update(); //override;
	
	void OnEvent(const TEvent &aEvent) override;
	
	const char *GetModuleName() const /*override*/ {return "Graphics";}
private:
	bool OpenWindow();
	void ProcessEvents(); // process ui events (windows messages/x events)
	
	const IServiceLocator &mCoreEnv;
	
	IGraphicsImpl *mpImpl{nullptr};
	IRender *mpRender{nullptr};
};

}; // namespace rz