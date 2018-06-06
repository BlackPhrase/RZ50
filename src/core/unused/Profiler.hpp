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

#include "core/IEventSystem.hpp"

namespace rz
{

class CProfiler final : public IEventListener
{
public:
	CProfiler() = default;
	~CProfiler() = default;
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
	
	void OnEvent(const TEvent &aEvent) override;
private:
};

}; // namespace rz