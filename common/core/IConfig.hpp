#pragma once

namespace rz
{

struct IConfig // IConfigReader
{
	virtual const char *GetString(const char *asKey, const char *asDefValue = "") const = 0;
	virtual int GetInt(const char *asKey, int anDefValue = 0) const = 0;
	virtual float GetFloat(const char *asKey, float afDefValue = 0.0f) const = 0;
	virtual bool GetBool(const char *asKey, bool abDefValue = true) const = 0;
};

}; // namespace rz