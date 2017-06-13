#pragma once

#include "core/ISubSystem.hpp"
#include "graphics/IGraphics.hpp"
#include "core/TCoreEnv.hpp"
#include "core/IEventSystem.hpp"

namespace rz
{

struct IGraphicsImpl;

class CGraphics : public ISubSystem, IGraphics, IEventListener
{
public:
	CGraphics(IGraphicsImpl *apImpl) : mpImpl(apImpl){}
	~CGraphics() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	void OnEvent(const TEvent &aEvent);
	
	const char *GetSubSystemName() const {return "Graphics";}
private:
	bool OpenWindow();
	void ProcessEvents(); // process ui events (windows messages/x events)
	
	const TCoreEnv *mpCoreEnv{nullptr};
	IGraphicsImpl *mpImpl{nullptr};
};

}; // namespace rz