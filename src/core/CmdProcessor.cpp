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