#pragma once

#include "fs/IFile.hpp"

class CFile final : public IFile
{
public:
	const char *GetName() const override;
	const char *GetPath() const override;
};