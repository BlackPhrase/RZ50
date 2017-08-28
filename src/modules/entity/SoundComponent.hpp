#pragma once

#include "entity/ISoundComponent.hpp"

namespace rz
{

class CSoundComponent : public ISoundComponent
{
public:
	CSoundComponent() = default;
	~CSoundComponent() = default;
	
	const char *GetName() const override {return "Sound";}
private:
};

}; // namespace rz