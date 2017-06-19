#pragma once

namespace rz
{

struct IConfig
{
	virtual const char *GetString(const char *asKey, const char *asDefault = "") const = 0;
	virtual int GetInt(const char *asKey, int anDefault = 0) const = 0;
	virtual float GetFloat(const char *asKey, float afDefault = 0.0f) const = 0;
	virtual bool GetBool(const char *asKey, bool abDefault = true) const = 0;
};

}; // namespace rz