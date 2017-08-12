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