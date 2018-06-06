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

#include "CmdProcessor.hpp"
#include "Core.hpp"
#include "ICmdHandler.hpp"
#include "CmdBuffer.hpp"
#include "CmdExecutor.hpp"
#include "CmdContainer.hpp"

namespace rz
{

CCmdProcessor::CCmdProcessor(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
CCmdProcessor::~CCmdProcessor() = default;

void CCmdProcessor::Init(IServiceLocator &aCoreEnv, CCore *apCore) // TODO: REV THIS
{
	mpExecutor = std::make_unique<CCmdExecutor>(apCore);
	mpBuffer = std::make_unique<CCmdBuffer>(mpExecutor.get());
	mpContainer = std::make_unique<CCmdContainer>();
	
	mpExecutor->Init();
	
	aCoreEnv.ProvideCmdProcessor(*this);
};

void CCmdProcessor::AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
{
	//if(mpVarContainer->IsPresent(asName))
		//return;
	
	mpContainer->Add(asName, afnCallback, asDesc);
};

void CCmdProcessor::BufferText(const char *asText, InsertMode aeMode)
{
	/*
	switch(InsertMode)
	{
	case Insert:
		mpBuffer->InsertText(asText);
		break;
	case Append:
		mpBuffer->AppendText(asText);
		break;
	};
	*/
};

void CCmdProcessor::ExecText(const char *asText)
{
	// TODO: lock or atomic?
	
	mCoreEnv.GetLog().Debug("CCmdProcessor::ExecText(\"%s\")", asText);
	
	//CCmdArgs Cmd(asText);
	//mpExecutor->ExecArgs(Cmd);
	
	mpExecutor->ExecString(asText);
};

void CCmdProcessor::ExecBuffer()
{
	mpBuffer->Exec();
};

}; // namespace rz