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

#pragma once

#include <memory>
#include <functional>
#include "core/ICore.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CServiceLocator;
class CModuleContainer;
class CEventDispatcher;
class CPluginManager;
class CStatsPrinter;
class CCmdProcessor;
struct ITextConsole;
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
	CCore();
	~CCore();
	
	bool Init(const TInitParams &aInitParams) override;
	void Shutdown() override;
	
	void Frame() override;
	
	void RequestClose();
	bool IsCloseRequested() const override {return mbWantQuit;}
	
	const IServiceLocator &GetEnv() const override {return (const IServiceLocator &)*mpEnv.get();}
	
	void GetStatistics(TEngineStatistics &aStatistics);
private:
	double GetTimeStep() const {return 1.0f / mfUpdateFreq;}
	
	void SetUpdateFreq(float fFreq){mfUpdateFreq = fFreq;}
	float GetUpdateFreq() const {return mfUpdateFreq;}
	
	//TCoreEnv mEnv{};
	TEngineStatistics mStats{};
	
	std::unique_ptr<CServiceLocator> mpEnv;
	std::unique_ptr<CModuleContainer> mpModuleContainer;
	std::unique_ptr<CEventDispatcher> mpEventDispatcher;
	std::unique_ptr<CPluginManager> mpPluginManager;
	std::unique_ptr<CStatsPrinter> mpStatsPrinter;
	std::unique_ptr<CCmdProcessor> mpCmdProcessor;
	std::unique_ptr<ITextConsole> mpTextConsole;
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