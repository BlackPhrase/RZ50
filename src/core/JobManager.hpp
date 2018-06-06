/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

namespace rz
{

// Each thread should be connected to this functor
class CThreadLoop
{
public:
	//CThreadLoop(const tTaskQue &aTaskQue) : mTaskQue(aTaskQue){}
	~CThreadLoop() = default;
	
	//void operator();
private:
	//const tTaskQue &mTaskQue;
};

class CJobManager
{
public:
	CJobManager(/*int anMaxThreads*/);
	~CJobManager() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
	
	// AddJob
	//void QueJob(const TJob &aJob);
private:
	//tThreadVec mvThreadPool;
	
	// TODO: ring buffer of jobs
};

}; // namespace rz