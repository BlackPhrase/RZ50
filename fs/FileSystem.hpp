#pragma once

#include "fs/IFileSystem.hpp"

class CFileSystem : public IFileSystem
{
public:
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	IFile *OpenFile(const char *asPath, const char *asMode);
	void CloseFile(IFile *apFile);
};