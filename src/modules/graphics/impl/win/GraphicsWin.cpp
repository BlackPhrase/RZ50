/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "GraphicsWin.hpp"

namespace rz
{

CGraphicsWin *CGraphicsWin::pGraphicsWin = nullptr;

CGraphicsWin::~CGraphicsWin() //Shutdown
{
};

bool CGraphicsWin::Init(const IServiceLocator &aCoreEnv)
{
	pGraphicsWin = this;
	mpCoreEnv = &aCoreEnv;
	
	return true;
};

bool CGraphicsWin::OpenWindow(int anWidth, int anHeight)
{
	return true;
};

void CGraphicsWin::ProcessEvents()
{
	static MSG Msg{};
	
	while(PeekMessage(&Msg, mhWnd, 0, 0, PM_REMOVE))
	{
		if(Msg.message == WM_QUIT)
			break;
		
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	};
};

void CGraphicsWin::RequestClose()
{
	mpCoreEnv->GetCmdProcessor().ExecText("exit");
};

}; // namespace rz