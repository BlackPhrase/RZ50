#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;

/// Core initialization parameters
struct TCoreInitParams
{
	char sConfigName[32] = {};  ///< Name of the config file to use
	const char *sCmdLine{""};   ///< Application command line

	//tWinHandle hCustomWindow{}; ///< Custom application window
	
	//int nMaxUPS{0}; ///< Max updates per second
	//int nMaxFPS{0}; ///< Max frames per second
};

struct ICore
{
	/// Initialize the core
	virtual bool Init(const TCoreInitParams &aInitParams) = 0;
	
	/// Shutdown the core
	virtual void Shutdown() = 0;
	
	/// Run a single frame
	virtual void Frame() = 0;
	
	//virtual void Run() = 0;
	
	/// @return true if close is requested
	virtual bool IsCloseRequested() const = 0; // WantQuit
	
	///
	virtual const TCoreEnv &GetEnv() const = 0;
	
	virtual bool RegisterSubSystem(const ISubSystem &apSubSystem) = 0;
	virtual ISubSystem *GetSubSystem(const char *asName) const = 0;
};

using pfnGetCore = ICore *(*)();

}; // namespace rz