#include "FileSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

bool CFileSystem::Init(const TCoreEnv &aCoreEnv)
{
	mpCoreEnv = &aCoreEnv;
	
	mpCoreEnv->pLog->Write("Initializing the fs module...");
	return true;
};

void CFileSystem::Shutdown()
{
	mpCoreEnv->pLog->Write("Shutting down the fs module...");
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