#pragma once

struct IFile;

struct IFileSystem
{
	virtual IFile *OpenFile(const char *asPath, const char *asMode) const = 0;
	virtual void CloseFile(IFile *apFile) = 0;
};