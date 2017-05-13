#include "FileSystem.hpp"

namespace rz
{

CLoggedFileSystem::Init(const TCoreEnvironment &aCoreEnv)
{
	aCoreEnv.pLog->Write("Initializing the fs module...");
	return mpImpl->Init(aCoreEnv);
};

CLoggedFileSystem::Shutdown()
{
	aCoreEnv.pLog->Write("Shutting down the fs module...");
	mpImpl->Shutdown();
};

IFile *CLoggedFileSystem::OpenFile(const char *asName, const char *asMode)
{
	aCoreEnv.pLog->Write("Opening the file %s (Mode: %s)", asName, asMode);
	return mpImpl->OpenFile(asName, asMode);
};

void CLoggedFileSystem::CloseFile(IFile *apFile)
{
	aCoreEnv.pLog->Write("Closing the file %s (%p)", apFile->GetName(), apFile);
	mpImpl->CloseFile(apFile);
};

}; // namespace rz