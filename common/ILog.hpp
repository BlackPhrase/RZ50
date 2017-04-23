#pragma once

struct ILog
{
	virtual void Write(const char *asMsg, ...) = 0;
};