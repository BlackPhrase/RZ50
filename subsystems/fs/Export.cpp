#include "core/CoreTypes.hpp"
#include "FileSystem.hpp"

//DECLARE_SUBSYSTEM(CFileSystem, GetFileSystemSubSystem)

C_EXPORT rz::ISubSystem *GetFS()
{
	static rz::CFileSystem FileSystem;
	return &FileSystem;
};