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