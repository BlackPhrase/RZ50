#pragma once

#include "core/ISubSystem.hpp"
#include "fs/IFileSystem.hpp"

namespace rz
{

class CFileSystem final : public ISubSystem, IFileSystem
{
public:
	CFileSystem(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CFileSystem() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	IFile *OpenFile(const char *asPath, const char *asMode) const override;
	void CloseFile(const IFile &apFile) override;
	
	const char *GetSubSystemName() const override {return "FileSystem";}
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz