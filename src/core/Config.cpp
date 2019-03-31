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

#include "Config.hpp"

namespace rz
{

void CConfig::SetString(const char *asKey, const char *asValue)
{
	mmapKeys[asKey] = asValue;
};

void CConfig::SetInt(const char *asKey, int anValue)
{
	mmapKeys[asKey] = anValue;
};

void CConfig::SetFloat(const char *asKey, float afValue)
{
	mmapKeys[asKey] = afValue;
};

void CConfig::SetBool(const char *asKey, bool abValue)
{
	mmapKeys[asKey] = abValue;
};

const char *CConfig::GetString(const char *asKey, const char *asDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return Key->second.c_str();
	
	return asDefault;
};

int CConfig::GetInt(const char *asKey, int anDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return atoi(Key->second.c_str());
	
	return anDefault;
};

float CConfig::GetFloat(const char *asKey, float afDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return atof(Key->second.c_str());
	
	return afDefault;
};

bool CConfig::GetBool(const char *asKey, bool abDefault) const
{
	auto Key = mmapKeys.find(asKey);
	
	if(Key != mmapKeys.end())
		return (Key->second == "true") ? true : false; // TODO: fix
	
	return abDefault;
};

}; // namespace rz