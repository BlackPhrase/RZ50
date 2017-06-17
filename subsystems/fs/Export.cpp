#include "core/CoreTypes.hpp"
#include "FileSystem.hpp"

//DECLARE_SUBSYSTEM(CFileSystem, GetFileSystemSubSystem)

C_EXPORT rz::ISubSystem *GetFS(const rz::TCoreEnv &aCoreEnv)
{
	static rz::CFileSystem FileSystem(aCoreEnv);
	return &FileSystem;
};