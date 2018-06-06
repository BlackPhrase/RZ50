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

#include "StatsPrinter.hpp"
#include "Core.hpp"
#include "core/ILog.hpp"

namespace rz
{

void CStatsPrinter::PrintToLog(const TEngineStatistics &aStats, ILog *apLog)
{
	if(!apLog) // TODO: fix
		return;
	
	apLog->Info("Statistics:\n"
				"\t- Total Frames: %d\n"
				"\t- Min. FPS: %.2f\n"
				"\t- Max. FPS: %.2f\n"
				"\t- Avg. FPS: %.2f\n"
				"\t- Avg. FrameTime %f",
				// TODO: UPS per core
				// TODO: Cores?
				aStats.nTotalFrames,
				aStats.fMinFPS,
				aStats.fMaxFPS,
				aStats.fAvgFPS,
				aStats.fAvgFrameTime);
};

}; // namespace rz