#pragma once

namespace rz
{

struct IArchive
{
	virtual IFile *OpenFile(const char *asName) = 0; // return IArchiveFile?
	virtual void CloseFile(IFile *apFile) = 0;
};

}; // namespace rz