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

#include "Sound.hpp"
//#include "SoundChannel.hpp"

namespace rz
{

bool CSound::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Sound");
	mCoreEnv.pLog->Info("Sound: Null");
	return true;
};

void CSound::Shutdown()
{
};

void CSound::Update()
{
	mCoreEnv.pCmdProcessor->Append("play test");
	
	//mCoreEnv.pUpdateLog->TraceUpdate("Sound");
	
	//for(auto It : mvChannels)
		//It->Update();
};

/*
ISoundChannel *CSound::CreateChannel()
{
	//return mvChannels.emplace_back();
	return nullptr;
};
*/

}; // namespace rz