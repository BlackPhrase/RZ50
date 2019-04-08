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

#include "Sound.hpp"
//#include "SoundChannel.hpp"

namespace rz::sound
{

bool CSound::Init(const TCoreEnv &aCoreEnv)
{
	mCoreEnv.pLog->TraceInit("Sound");
	
	if(mpImpl)
		return mpImpl->Init();
	
	return true;
};

void CSound::Shutdown()
{
	if(mpImpl)
		mpImpl->Shutdown();
};

void CSound::Update()
{
	mCoreEnv.pCmdProcessor->Append("play test");
	
	//mCoreEnv.pUpdateLog->TraceUpdate("Sound");
	
	//for(auto It : mvChannels)
		//It->Update();
	
	if(mpWorld)
		mpWorld->Update();
};

/*
ISoundChannel *CSound::CreateChannel()
{
	//return mvChannels.emplace_back();
	return nullptr;
};
*/

ISoundWorld &CSound::CreateWorld()
{
	return new CSoundWorld();
};

void CSound::DestroyWorld(ISoundWorld &aWorld)
{
	delete std::addressof(aWorld);
};

void CSound::SetCurrentWorld(const ISoundWorld &aWorld)
{
	if(std::addressof(mpWorld) != aWorld)
		std::addressof(mpWorld) = aWorld;
};

}; // namespace rz::sound