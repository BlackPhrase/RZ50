#pragma once

#include "ISubSystem.hpp"
#include "fs/IFileSystem.hpp"

class CFileSystem final : public ISubSystem<IFileSystem>
{
public:
	bool Init(const TCoreEnvironment &aCoreEnv) override;
	void Shutdown() override;
	
	IFile *OpenFile(const char *asPath, const char *asMode) override;
	void CloseFile(IFile *apFile) override;
	
	const char *GetSubSystemName() const override {return "FileSystem";}
};