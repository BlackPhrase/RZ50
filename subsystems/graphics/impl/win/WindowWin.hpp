#pragma once

#include "graphics/IWindow.hpp"

namespace rz
{

// TODO: apply usage of vectors for pos/size
class CWindowWin : public IWindow
{
public:
	CWindowWin() = default;
	~CWindowWin() = default;
	
	int GetX() const;
	int GetY() const;
	
	int GetWidth() const;
	int GetHeight() const;
	
	tWinHandle GetHandle() const {return mHandle;}
private:
	tWinHandle mHandle{nullptr};
};

}; // namespace rz