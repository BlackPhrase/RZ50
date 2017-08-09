#include <cstring>
#include "CmdProcessor.hpp"
#include "Core.hpp"
#include "ICmdHandler.hpp"
#include "DefaultCmdHandler.hpp"
#include "CmdBuffer.hpp"
#include "CmdExecutor.hpp"

namespace rz
{

void CCmdProcessor::Init(TCoreEnv &aCoreEnv) // TODO: REV THIS
{
	mpExecutor->Init();
	
	aCoreEnv.pCmdProcessor = this;
};

void CCmdProcessor::BufferText(const char *asText, InsertMode aeMode)
{
	switch(InsertMode)
	{
	case Insert:
		mpBuffer->InsertText(asText);
		break;
	case Append:
		mpBuffer->AppendText(asText);
		break;
	};
};

void CCmdProcessor::ExecText(const char *asText)
{
	// TODO: lock or atomic?
	
	mCoreEnv.pLog->Debug("CCmdProcessor::ExecText(\"%s\")", asText);
	
	if(!strcmp(asText, "exit"))
		mpCore->RequestClose(); // TODO: REMOVE THIS
	
	CCmdArgs Cmd(asText);
	mpExecutor->ExecArgs(Cmd);
};

void CCmdProcessor::ExecBuffer()
{
	mpBuffer->Exec();
};

}; // namespace rz