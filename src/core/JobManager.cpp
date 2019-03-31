/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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