#include "FileSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

bool CFileSystem::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->TraceInit("FileSystem");
	return true;
};

void CFileSystem::Shutdown()
{
	mpCoreEnv->pLog->TraceShutdown("FileSystem");
};

void CFileSystem::Update()
{
};

IFile *CFileSystem::OpenFile(const char *asName, const char *asMode) const
{
	//mpCoreEnv->pLog->Write("Opening the file %s (Mode: %s)", asName, asMode);
	return nullptr;
};

void CFileSystem::CloseFile(const IFile &apFile)
{
	//mpCoreEnv->pLog->Write("Closing the file %s (%p)", apFile->GetName(), apFile);
};

}; // namespace rz