#pragma once

#include "entity/ILightComponent.hpp"

namespace rz
{

class CLightComponent : public ILightComponent
{
public:
	CLightComponent() = default;
	~CLightComponent() = default;
	
	const char *GetName() const override {return "Light";}
private:
};

}; // namespace rz