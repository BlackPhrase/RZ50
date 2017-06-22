#include "FileSystemModule.hpp"
#include "core/TCoreEnv.hpp"
#include "FileSystem.hpp"

namespace rz
{

bool CFileSystemModule::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("FileSystem");
	mCoreEnv.pLog->Info("FileSystem: Null");
	
	mpFileSystem = std::make_unique<CFileSystem>(aCoreEnv);
	return true;
};

void CFileSystemModule::Shutdown()
{
};

void CFileSystemModule::Update()
{
};

}; // namespace rz