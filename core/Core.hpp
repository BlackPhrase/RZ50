#pragma once

#include <memory>
#include "core/ICore.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CSubSystemManager;
class CPluginManager;
class CEventManager;
class CCmdProcessor;
class CCmdLine;
class CMemory;
class CLog;

struct TEngineStatistics
{
	float fMinFPS{0.0f};
	float fMaxFPS{0.0f};
	
	float fAvgFPS{0.0f};
	float fAvgFrameTime{0.0f};
	
	int nUPS{0};
	int nFPS{0};
};

class CCore final : public ICore
{
public:
	CCore(); //= default;
	~CCore(); //= default;
	
	bool Init(const TCoreInitParams &aInitParams) override;
	void Shutdown() override;
	
	void Frame() override;
	
	void RequestClose();
	bool IsCloseRequested() const override {return mbWantQuit;}
	
	const TCoreEnv &GetEnv() const override {return mEnv;}
	
	bool RegisterSubSystem(const ISubSystem &apSubSystem);
	ISubSystem *GetSubSystem(const char *asName) const;
	
	void GetStatistics(TEngineStatistics &aStatistics);
private:
	void PrintStats();
	
	double GetTimeStep() const {return 1.0f / mfUpdateFreq;}
	
	void SetUpdateFreq(float fFreq){mfUpdateFreq = fFreq;}
	float GetUpdateFreq() const {return mfUpdateFreq;}
	
	TCoreEnv mEnv{};
	TEngineStatistics mStats{};
	
	std::unique_ptr<CSubSystemManager> mpSubSystemManager;
	std::unique_ptr<CPluginManager> mpPluginManager;
	std::unique_ptr<CEventManager> mpEventManager;
	std::unique_ptr<CCmdProcessor> mpCmdProcessor;
	std::unique_ptr<CCmdLine> mpCmdLine;
	std::unique_ptr<CMemory> mpMemory;
	std::unique_ptr<CLog> mpLog;
	
	float mfUpdateFreq{0.0f};
	
	bool mbInitialized{false};
	bool mbWantQuit{false};
};

}; // namespace rz