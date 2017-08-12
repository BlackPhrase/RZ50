#pragma once

namespace rz
{

struct ICmdArgs;

class CCmdParser
{
public:
	CCmdParser() = default;
	~CCmdParser() = default;
	
	const ICmdArgs &Parse(const char *asText);
};

}; // namespace rz