/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <memory>

#include "core/IEnginePlugin.hpp"

namespace rz::input
{

class CInput;

class CInputModulePlugin final : public core::plugin::IEnginePlugin
{
public:
	CInputModulePlugin() = default;
	~CInputModulePlugin() = default;
	
	bool OnLoad(const core::IServiceLocator &aCoreEnv) override;
	void OnUnload() override;
private:
	std::unique_ptr<CInput> mpInput;
};

}; // namespace rz::input