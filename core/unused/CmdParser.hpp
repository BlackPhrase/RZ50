#pragma once

namespace rz
{

class CCmdParser
{
public:
	CCmdParser() = default;
	~CCmdParser() = default;
	
	const ICmdArgs &Parse(const char *asText);
};

}; // namespace rz