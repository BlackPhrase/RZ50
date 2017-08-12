#pragma once

namespace rz
{

struct TEngineStatistics;

class CStatsPrinter final
{
public:
	CStatsPrinter() = default;
	~CStatsPrinter() = default;

	void PrintToLog(const TEngineStatistics &aStats, ILog *apLog);
};

}; // namespace rz