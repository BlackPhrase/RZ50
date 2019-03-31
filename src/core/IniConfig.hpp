/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "core/CoreTypes.hpp"
#include "core/IConfig.hpp"

typedef struct _dictionary_ dictionary;

namespace rz::core
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

}; // namespace rz::core