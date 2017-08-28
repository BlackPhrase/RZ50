#pragma once

#include <memory>
#include "core/ISubSystem.hpp"

namespace rz
{

struct IFileSystem;

class CFileSystemModule final : public ISubSystem
{
public:
	CFileSystemModule(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CFileSystemModule() = default;
	
	bool Init(const TCoreEnv &aCoreEnv) override;
	void Shutdown() override;
	
	void Update() override;
	
	const char *GetSubSystemName() const override {return "FileSystem";}
private:
	std::unique_ptr<IFileSystem> mpFileSystem;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz