#pragma once

namespace rz
{

struct IServiceLocator;

struct ICore
{
	/// Initialization parameters
	struct TInitParams
	{
		char sConfigName[32] = {};  ///< Name of the config file to use
		const char *sCmdLine{""};   ///< Application command line

		//tWinHandle hCustomWindow{}; ///< Custom application window
		
		//int nMaxUPS{0}; ///< Max updates per second
		//int nMaxFPS{0}; ///< Max frames per second
	};
	
	/// Initialize the core
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

}; // namespace rz