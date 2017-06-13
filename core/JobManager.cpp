#include "JobManager.hpp"

namespace rz
{

/*
void CThreadLoop::operator()
{
	// Sleep until some semaphore signal that there is a new tasks
	// Assign tasks from the task queue to available threads
	// If there is no new tasks then sleep again
	
	while(true)
	{
		//if(!mTaskQue.empty())
		{
			
		};
	};
};
*/

CJobManager::CJobManager()
{
	//int nMaxThreads = std::thread::hardware_concurrency();
	
	//for(auto i = 0; i < nMaxThreads; ++i)
		//mvThreadPool.push_back(new std::thread(CThreadLoop));
};

}; // namespace rz