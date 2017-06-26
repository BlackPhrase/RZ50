#pragma once

namespace rz
{

struct IMessageEventListener
{
	virtual void OnInfo(const char *asMsg, ...){}
	virtual void OnDebug(const char *asMsg, ...){}
	virtual void OnWarning(const char *asMsg, ...){}
	virtual void OnError(const char *asMsg, ...){}
	virtual void OnFatal(const char *asMsg, ...){}
};

}; // namespace rz