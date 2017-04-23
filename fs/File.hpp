#pragma once

#include "fs/IFile.hpp"

class CFile : public IFile
{
public:
	const char *GetName() const;
	const char *GetPath() const;
};