#pragma once

namespace rz
{

struct ITexture
{
	///
	virtual void Bind() = 0;
	
	///
	virtual void Unbind() = 0;
	
	///
	virtual unsigned int GetID() const = 0;
	
	///
	virtual int GetWidth() const = 0;
	
	///
	virtual int GetHeight() const = 0;
	
	///
	virtual int GetBPP() const = 0;
};

}; // namespace rz