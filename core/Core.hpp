#pragma once

#include <memory>
#include "core/ICore.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CSubSystemManager;
class CPluginManager;
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
	bool IsCloseRequested() const override {return mbWantQuit;}
	
	bool RegisterSubSystem(const ISubSystem &apSubSystem);
	ISubSystem *GetSubSystem(const char *asName) const;
	
	void GetStatistics(TEngineStatistics &aStatistics);
private:
	void PrintStats();
	
	TCoreEnv mEnv{};
	TEngineStatistics mStats{};
	
	std::unique_ptr<CSubSystemManager> mpSubSystemManager;
	std::unique_ptr<CPluginManager> mpPluginManager;
	std::unique_ptr<CMemory> mpMemory;
	std::unique_ptr<CLog> mpLog;
	
	bool mbInitialized{false};
	bool mbWantQuit{false};
};

}; // namespace rz