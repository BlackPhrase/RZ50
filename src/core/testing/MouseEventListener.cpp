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

#include "MouseEventListener.hpp"

namespace rz
{

void CMouseEventListener::OnEvent(const TEvent &aEvent)
{
	//mCoreEnv.pLog->Debug("Got an event: %s", aEvent.sName);
	
	switch(aEvent.eType)
	{
	case TEvent::Type::MouseMove:
		auto MouseMoveEvent = static_cast<const TMouseMoveEvent*>(&aEvent);
		
		if(!MouseMoveEvent)
			return;
		
		mCoreEnv.GetLog().Debug("Got a mouse move event: %d, %d", MouseMoveEvent->nDeltaX, MouseMoveEvent->nDeltaY);
		break;
	};
};

}; // namespace rz