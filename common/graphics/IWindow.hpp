#pragma once

#include "core/CoreTypes.hpp"

namespace rz
{

struct IWindow
{
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
	
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
	
	virtual tWinHandle GetHandle() const = 0;
};

}; // namespace rz