#pragma once

#include "fs/IFileSystem.hpp"

class CFileSystem : public IFileSystem
{
public:
	IFile *OpenFile(const char *asPath, const char *asMode);
	void CloseFile(IFile *apFile);
};