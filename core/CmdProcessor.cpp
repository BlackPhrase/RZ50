#include <cstring>
#include "CmdProcessor.hpp"
#include "Core.hpp"
#include "ICmdHandler.hpp"
#include "DefaultCmdHandler.hpp"

namespace rz
{

void CCmdProcessor::Init()
{
	ICmdHandler *pDefaultCmdHandler = new CDefaultCmdHandler(mCoreEnv);
	//pDefaultCmdHandler->AddCommand();
	mlstHandlers.push_back(pDefaultCmdHandler);
};

void CCmdProcessor::Insert(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdBuffer.emplace_front(asCmd);
};

void CCmdProcessor::Append(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdBuffer.emplace_back(asCmd);
};

void CCmdProcessor::ExecText(const char *asText)
{
	// TODO: lock or atomic?
	
	mCoreEnv.pLog->Debug("CCmdProcessor::ExecText(\"%s\")", asText);
	
	if(!strcmp(asText, "exit"))
		mpCore->RequestClose(); // hacky
	
	// TODO: command handlers
	//CCmdArgs Cmd(asText);
	//mpCmdHandler->Exec(Cmd);
	
	for(auto It : mlstHandlers)
		if(It->HandleCmd(asText))
			return;
	
	//mCoreEnv.pLog->Error("No valid handler for command \"%s\"", sCmdName.c_str());
};

void CCmdProcessor::Exec()
{
	// TODO: lock or atomic?
	
	while(!mCmdBuffer.empty())
	{
		ExecText(mCmdBuffer.front().c_str());
		mCmdBuffer.pop_front();
	};
};

}; // namespace rz