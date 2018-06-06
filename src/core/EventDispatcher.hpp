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

#pragma once

#include <list>
#include <deque>
#include "core/IEventSystem.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

using tEventListenerList = std::list<IEventListener*>;

//tEventQue
using tEventDeque = std::deque<TEvent*>;

//CEventHandler
class CEventDispatcher final : public IEventDispatcher
{
public:
	CEventDispatcher(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CEventDispatcher() = default;
	
	void Update(); // TODO: updateable component interface
	
	void BroadcastEvent(const TEvent &aEvent) override;
	void QueEvent(const TEvent &aEvent) override;
	
	void DispatchEvents();
	
	void AddListener(IEventListener &aListener) override;
	void RemoveListener(const IEventListener &aListener) override;
private:
	//bool Poll(TEvent &aEvent);
	//bool Get(TEvent &aEvent);
	
	tEventListenerList mlstListeners;
	tEventDeque mEventQue;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz