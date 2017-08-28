#pragma once

namespace rz
{

class CPhysicsObject
{
public:
	CPhysicsObject() = default;
	~CPhysicsObject() = default;
	
	void Update(float afDeltaTime); // Integrate
	
	void SetPos(const CVec3f &avPos){mvPosition = avPos;}
	const CVec3f &GetPos() const {return mvPosition;}
	
	void SetVelocity(const CVec3f &avVelocity){mvVelocity = avVelocity;}
	const CVec3f &GetVelocity() const {return mvVelocity;}
private:
	CVec3f mvPosition{0.0f, 0.0f, 0.0f};
	CVec3f mvVelocity{0.0f, 0.0f, 0.0f};
};

}; // namespace rz