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

/// @file
/// @brief engine core interface

#pragma once

namespace rz::core
{

struct IServiceLocator;

struct ICore
{
	/// Initialization parameters
	struct TInitParams
	{
		char sConfigName[32]{};  ///< Name of the config file to use
		const char *sCmdLine{""};   ///< Application command line

		//tWinHandle hCustomWindow{}; ///< Custom application window
		
		//int nMaxUPS{0}; ///< Max updates per second
		//int nMaxFPS{0}; ///< Max frames per second
	};
	
	/// Initialize the core
	/// @return true if success
	virtual bool Init(const TInitParams &aInitParams) = 0;
	
	/// Shutdown the core
	virtual void Shutdown() = 0;
	
	/// Run a single frame
	virtual void Frame() = 0;
	
	//virtual void Run() = 0;
	
	/// @return true if close is requested
	virtual bool IsCloseRequested() const = 0; // WantQuit
	
	/// @return set of common components
	virtual const IServiceLocator &GetEnv() const = 0;
};

using pfnGetCore = ICore *(*)();

}; // namespace rz::core