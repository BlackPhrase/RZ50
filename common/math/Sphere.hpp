#pragma once

#include "Vec3.hpp"

namespace rz
{

struct TSphere
{
	TSphere() = default;
	TSphere(const TVec3 &avCenter, float afRadius) : vCenter(avCenter), fRadius(afRadius){}
	
	TVec3 vCenter{0.0f, 0.0f, 0.0f};
	float fRadius{0.0f};
};

}; // namespace rz