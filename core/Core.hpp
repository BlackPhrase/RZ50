#pragma once

#include <memory>

class CSubSystemManager;
class CMemory;
class CLog;

struct TEngineStatistics
{
	float fMinFPS{0.0f};
	float fMaxFPS{0.0f};
	float fAvgFPS{0.0f};
	
	int nUPS{0};
	int nFPS{0};
};

class CCore final : public ICore
{
	CCore() = default;
	~CCore() = default;
	
	bool Init() override;
	void Shutdown() override;
	
	void Frame() override;
	
	bool RegisterSubSystem(ISubSystem *apSubSystem);
	ISubSystem *GetSubSystem(const char *asName);
	
	void GetStatistics(TEngineStatistics &aStatistics);
private:
	void PrintStats();
	
	TCoreEnvironment mCoreEnv;
	TEngineStatistics mStats;
	
	std::unique_ptr<CSubSystemManager> mpSubSystemManager;
	std::unique_ptr<CMemory> mpMemory;
	std::unique_ptr<CLog> mpLog;
	
	bool mbInitialized{false};
};