/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <memory>
#include "ConfigFactory.hpp"
#include "IniConfig.hpp"

namespace rz
{

IConfig *CConfigFactory::LoadFromFile(const char *asName)
{
	//dictionary *pDict{iniparser_load(asName)};
	
	//if(!pDict)
		//return nullptr;
	
	//std::unique_ptr<IConfig> pConfig = std::make_unique<CIniConfig>(asName);
	
	//return pConfig.release();
	return nullptr;
};

}; // namespace rz