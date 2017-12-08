#pragma once

#include <windows.h>
#include "IGraphicsImpl.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

class CGraphicsWin final : public IGraphicsImpl
{
public:
	CGraphicsWin() = default;
	~CGraphicsWin(); // = default;
	
	bool Init(const IServiceLocator &aCoreEnv) override;
	//void Shutdown() override;
	
	bool OpenWindow(int anWidth, int anHeight) override;
	
	void ProcessEvents() override;
	
	void RequestClose();
	
	static CGraphicsWin *pGraphicsWin;
private:
	static LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	const IServiceLocator *mpCoreEnv{nullptr};
	
	HWND mhWnd{nullptr};
};

}; // namespace rz