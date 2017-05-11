#pragma once

namespace rz
{

struct IPhysicsBody
{
	virtual void SetMass(float afMass) = 0;
	virtual float GetMass() const = 0;
};

}; // namespace rz