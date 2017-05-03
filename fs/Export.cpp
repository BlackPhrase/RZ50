#include "LoggedFileSystem.hpp"
#include "FileSystem.hpp"

//DECLARE_SUBSYSTEM(CFileSystem, GetFileSystemSubSystem)

#ifndef RZ_STATIC_FILESYSTEM
	extern "C" EXPORT
#endif // RZ_STATIC_FILESYSTEM

ISubSystem *GetFileSystemSubSystem()
{
	static ISubSystem *pFileSystem = 
	
#ifdef RZ_LOGGED_FILESYSTEM
	new CLoggedFileSystem(
#endif

	new CFileSystem()
	
#ifdef RZ_LOGGED_FILESYSTEM
	);
#endif
	
	return pFileSystem;
};