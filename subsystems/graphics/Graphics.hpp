#pragma once

#include "core/ISubSystem.hpp"
#include "graphics/IGraphics.hpp"
#include "core/TCoreEnv.hpp"
#include "core/IEventSystem.hpp"

namespace rz
{

struct IGraphicsImpl;
struct IRender;

class CGraphics final : public ISubSystem, IGraphics, IEventListener
{
public:
	CGraphics(const TCoreEnv &aCoreEnv, IGraphicsImpl *apImpl, IRender *apRender)
		: mCoreEnv(aCoreEnv), mpImpl(apImpl), mpRender(apRender){}
	~CGraphics() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	void OnEvent(const TEvent &aEvent) override;
	
	const char *GetSubSystemName() const override {return "Graphics";}
private:
	bool OpenWindow();
	void ProcessEvents(); // process ui events (windows messages/x events)
	
	const TCoreEnv &mCoreEnv;
	
	IGraphicsImpl *mpImpl{nullptr};
	IRender *mpRender{nullptr};
};

}; // namespace rz