#pragma once

#include "Plane.hpp"

namespace rz
{

struct TFrustum
{
	enum class Side : int
	{
		Front,
		Back,
		Left,
		Right,
		Up,
		Down
	};
	
	TPlane mPlane[Side];
};

}; // namespace rz