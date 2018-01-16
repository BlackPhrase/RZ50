#pragma once

namespace rz
{

struct IFrameListener
{
	/// Pre-update stage
	/// @return true if should apply an update
	//virtual bool PreUpdate() = 0;
	
	/// Update stage
	virtual void Update() = 0;
	
	/// Post-update stage
	//virtual void PostUpdate();
};

}; // namespace rz