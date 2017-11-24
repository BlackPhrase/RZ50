#pragma once

#include "core/CoreTypes.hpp"
#include "core/IConfig.hpp"

typedef struct _dictionary_ dictionary;

namespace rz
{

class CIniConfig final : public IConfig
{
public:
	CIniConfig(const char *asName);
	~CIniConfig();
	
	void SetString(const char *asKey, const char *asValue);
	void SetInt(const char *asKey, int anValue);
	void SetFloat(const char *asKey, float afValue);
	void SetBool(const char *asKey, bool abValue);
	
	const char *GetString(const char *asKey, const char *asDefValue = "") const override;
	int GetInt(const char *asKey, int anDefValue = 0) const override;
	float GetFloat(const char *asKey, float afDefValue = 0.0f) const override;
	bool GetBool(const char *asKey, bool abDefValue = true) const override;
private:
	dictionary *mpDict{nullptr};
};

}; // namespace rz