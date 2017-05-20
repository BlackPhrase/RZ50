#pragma once

namespace rz
{

struct TProfileResult
{
	double fTime;
};

struct IProfileTimer
{
	//virtual void Start() = 0;
	virtual TProfileResult Stop() const = 0;
	
	virtual const char *GetName() const = 0;
};

struct IProfiler
{
	//virtual IProfileTimer &CreateTimer(const char *asName) = 0;
	virtual IProfileTimer &StartTiming(const char *asName) = 0;
};

}; // namespace rz