#include "LoggedFileSystem.hpp"
#include "FileSystem.hpp"

//DECLARE_SUBSYSTEM(CFileSystem, GetFileSystemSubSystem)

#ifndef RZ_STATIC_FILESYSTEM
	extern "C" EXPORT
#endif // RZ_STATIC_FILESYSTEM

rz::ISubSystem *GetFileSystemSubSystem()
{
	static rz::ISubSystem *pFileSystem = 
	
#ifdef RZ_LOGGED_FILESYSTEM
	new rz::CLoggedFileSystem(
#endif

	new rz::CFileSystem()
	
#ifdef RZ_LOGGED_FILESYSTEM
	);
#endif
	
	return pFileSystem;
};