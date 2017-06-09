#pragma once

namespace rz
{

class CConfig
{
public:
	CConfig() = default;
	~CConfig() = default;
	
	void SetString(const char *asKey, const char *asValue);
	void SetInt(const char *asKey, int anValue);
	void SetFloat(const char *asKey, float afValue);
	void SetBool(const char *asKey, bool abValue);
	
	const char *GetString(const char *asKey, const char *asDefault = "") const;
	int GetInt(const char *asKey, int anDefault = 0) const;
	float GetFloat(const char *asKey, float afDefault = 0.0f) const;
	bool GetBool(const char *asKey, bool abDefault = true) const;
private:
};

}; // namespace rz