#pragma once

namespace rz
{

struct TTask
{
	//
};

struct IScheduler
{
	virtual void AddTask(const TTask &aTask) = 0;
};

}; // namespace rz