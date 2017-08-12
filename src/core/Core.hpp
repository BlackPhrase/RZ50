#pragma once

#include <memory>
#include "core/ICore.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

class CSubSystemContainer;
class CEventDispatcher;
class CPluginManager;
class CStatsPrinter;
class CCmdProcessor;
struct ITextConsole;
class CConfigFactory;
class CCmdLine;
struct IConfig;
class CIniConfig;
class CMemory;
class CLog;

struct TEngineStatistics // TEngineStats
{
	float fMinFPS{0.0f};
	float fMaxFPS{0.0f};
	
	float fAvgFPS{0.0f};
	float fAvgFrameTime{0.0f};
	
	int nTotalFrames{0};
	
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
	
	void GetStatistics(TEngineStatistics &aStatistics);
private:
	double GetTimeStep() const {return 1.0f / mfUpdateFreq;}
	
	void SetUpdateFreq(float fFreq){mfUpdateFreq = fFreq;}
	float GetUpdateFreq() const {return mfUpdateFreq;}
	
	TCoreEnv mEnv{};
	TEngineStatistics mStats{};
	
	std::unique_ptr<CSubSystemContainer> mpSubSystemContainer;
	std::unique_ptr<CEventDispatcher> mpEventDispatcher;
	std::unique_ptr<CPluginManager> mpPluginManager;
	std::unique_ptr<CStatsPrinter> mpStatsPrinter;
	std::unique_ptr<CCmdProcessor> mpCmdProcessor;
	std::unique_ptr<ITextConsole> mpTextConsole;
	//std::unique_ptr<CConfigFactory> mpConfigFactory;
	std::unique_ptr<CCmdLine> mpCmdLine;
	//std::unique_ptr<IConfig> mpConfig;
	std::unique_ptr<CIniConfig> mpConfig;
	std::unique_ptr<CMemory> mpMemory;
	std::unique_ptr<CLog> mpLog;
	
	double mfUpdateFreq{0.0f};
	
	// Accumulated count of frametimes
	double mfFrameTimeAcc{0.0f};
	
	bool mbInitialized{false};
	bool mbWantQuit{false};
};

}; // namespace rz