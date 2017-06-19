#pragma once

#include <unordered_map>
#include "core/CoreTypes.hpp"
#include "core/IConfig.hpp"

namespace rz
{

using tKeyValueMap = std::unordered_map<string, string>;

class CConfig final : public IConfig
{
public:
	CConfig() = default;
	~CConfig() = default;
	
	void SetString(const char *asKey, const char *asValue);
	void SetInt(const char *asKey, int anValue);
	void SetFloat(const char *asKey, float afValue);
	void SetBool(const char *asKey, bool abValue);
	
	const char *GetString(const char *asKey, const char *asDefault = "") const override;
	int GetInt(const char *asKey, int anDefault = 0) const override;
	float GetFloat(const char *asKey, float afDefault = 0.0f) const override;
	bool GetBool(const char *asKey, bool abDefault = true) const override;
private:
	tKeyValueMap mmapKeys;
};

}; // namespace rz