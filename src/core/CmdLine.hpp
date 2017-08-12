#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

class CCmdLine final
{
public:
	CCmdLine(const char *asCmdLine);
	CCmdLine(int argc, char **argv);
	~CCmdLine() = default;
	
	const char *GetArgValue(int anIndex) const;
	
	bool HasArg(const char *asName) const;
	
	uint GetArgCount() const;
private:
	// TODO
};

}; // namespace rz