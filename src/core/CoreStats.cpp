#include "Core.hpp"

namespace rz
{

void TEngineStatistics::Print(ILog *apLog)
{
	apLog->Info("Statistics:\n"
				"\t- Total Frames: %d\n"
				"\t- Min. FPS: %.2f\n"
				"\t- Max. FPS: %.2f\n"
				"\t- Avg. FPS: %.2f\n"
				"\t- Avg. FrameTime %f",
				// TODO: UPS per core
				// TODO: Cores?
				nTotalFrames,
				fMinFPS,
				fMaxFPS,
				fAvgFPS,
				fAvgFrameTime);
};

};