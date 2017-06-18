#pragma once

namespace rz
{

using pfnCmdCallback = void (*)();

struct ICmdHandler
{
	virtual void HandleCmd(const char *asText) = 0;
	
	virtual void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc = "") = 0;
};

}; // namespace rz