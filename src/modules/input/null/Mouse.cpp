#include <cstdlib>
#include "Mouse.hpp"

namespace rz
{

void CNullMouse::Update()
{
	TMouseMoveEvent MouseMoveEvent(rand() % 1024, rand() % 512);
	mCoreEnv.GetEventDispatcher().BroadcastEvent(MouseMoveEvent);
};

bool CNullMouse::IsButtonPressed(Button aeButton) const
{
	return false;
};

}; // namespace rz