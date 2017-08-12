#include <cstring>
#include "CmdProcessor.hpp"
#include "Core.hpp"
#include "ICmdHandler.hpp"
#include "CmdBuffer.hpp"
#include "CmdExecutor.hpp"

namespace rz
{

CCmdProcessor::CCmdProcessor(const TCoreEnv &aCoreEnv, CCore *apCore) : mCoreEnv(aCoreEnv), mpCore(apCore){Init(const_cast<TCoreEnv&>(mCoreEnv));} //= default;
CCmdProcessor::~CCmdProcessor() = default;

void CCmdProcessor::Init(TCoreEnv &aCoreEnv) // TODO: REV THIS
{
	mpExecutor = std::make_unique<CCmdExecutor>();
	mpBuffer = std::make_unique<CCmdBuffer>(mpExecutor.get());
	
	mpExecutor->Init();
	
	aCoreEnv.pCmdProcessor = this;
};

void CCmdProcessor::AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
{
	//mlstCmds.emplace_back(asName, afnCallback, asDesc);
	mlstCmds.push_back(new CCmd(asName, afnCallback, asDesc));
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
	
	mCoreEnv.pLog->Debug("CCmdProcessor::ExecText(\"%s\")", asText);
	
	if(!strcmp(asText, "exit"))
		mpCore->RequestClose(); // TODO: REMOVE THIS
	
	//CCmdArgs Cmd(asText);
	//mpExecutor->ExecArgs(Cmd);
};

void CCmdProcessor::ExecBuffer()
{
	mpBuffer->Exec();
};

}; // namespace rz