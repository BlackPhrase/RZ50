#pragma once

#include "ISubSystem.hpp"
#include "fs/IFileSystem.hpp"

class CFileSystem : public ISubSystem<IFileSystem>
{
public:
	bool Init(const TCoreEnvironment &aCoreEnv);
	void Shutdown();
	
	IFile *OpenFile(const char *asPath, const char *asMode);
	void CloseFile(IFile *apFile);
	
	const char *GetSubSystemName() const {return "FileSystem";}
};