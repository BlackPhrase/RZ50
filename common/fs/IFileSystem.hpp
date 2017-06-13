#pragma once

namespace rz
{

struct IFile;
struct ISubSystem;

struct IFileSystem
{
	///
	virtual IFile *OpenFile(const char *asPath, const char *asMode) const = 0;
	
	///
	virtual void CloseFile(const IFile &apFile) = 0;
};

using pfnGetFS = ISubSystem *(*)();

}; // namespace rz