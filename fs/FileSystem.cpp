#include "FileSystem.hpp"

CFileSystem::Init(const TCoreEnvironment &aCoreEnv)
{
	return true;
};

CFileSystem::Shutdown()
{
};

IFile *CFileSystem::OpenFile(const char *asName, const char *asMode)
{
	return nullptr;
};

void CFileSystem::CloseFile(IFile *apFile)
{
};