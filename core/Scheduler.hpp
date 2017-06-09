#pragma once

#include <deque>
#include "core/IScheduler.hpp"

namespace rz
{

using tPendingTaskQue = std::deque<TTask*>;

class CScheduler : public IScheduler
{
public:
	CScheduler() = default;
	~CScheduler() = default;
	
	void Update();
	
	void AddTask(const TTask &aTask);
private:
	// TODO: task queue/deque
	// TODO: worker threads (thread pool)
};

}; // namespace rz