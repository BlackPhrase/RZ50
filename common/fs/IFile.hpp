#pragma once

struct IFile
{
	virtual void Write() = 0;
	virtual void Read() = 0;
	
	virtual const char *GetName() const = 0;
	virtual const char *GetPath() const = 0;
};