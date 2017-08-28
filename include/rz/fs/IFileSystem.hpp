#pragma once

namespace rz
{

struct ISubSystem;
struct TCoreEnv;
struct IFile;

struct IFileSystem
{
	///
	virtual IFile *OpenFile(const char *asPath, const char *asMode) const = 0;
	
	///
	virtual void CloseFile(const IFile &apFile) = 0;
};

using pfnGetFS = ISubSystem *(*)(const TCoreEnv &aCoreEnv);

}; // namespace rz