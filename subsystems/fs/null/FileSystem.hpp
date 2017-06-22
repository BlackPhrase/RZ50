#pragma once

#include "fs/IFileSystem.hpp"

namespace rz
{

class CFileSystem final : public IFileSystem
{
public:
	CFileSystem(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CFileSystem() = default;
	
	IFile *OpenFile(const char *asPath, const char *asMode) const override;
	void CloseFile(const IFile &apFile) override;
private:
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz