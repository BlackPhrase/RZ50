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

#include "SoundModulePlugin.hpp"
#include "Sound.hpp"
#include "core/IServiceLocator.hpp"

namespace rz::sound
{

bool CSoundModulePlugin::OnLoad(const core::IServiceLocator &aCoreEnv)
{
	aCoreEnv.pLog->TraceInit("Sound System: Default");
	
	mpSound = std::make_unique<CSound>(aCoreEnv);
	
	mpSound->Init();
	return true;
};

void CSoundModulePlugin::OnUnload()
{
	mpSound->Shutdown();
};

}; // namespace rz::sound