#include "core/CoreTypes.hpp"
#include "FileSystemModule.hpp"

//DECLARE_SUBSYSTEM(CFileSystem, GetFileSystemSubSystem)

C_EXPORT rz::ISubSystem *GetFS(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CFileSystemModule FileSystem(aCoreEnv);
	return &FileSystem;
};