#include <cstring>
#include "CmdProcessor.hpp"
#include "Core.hpp"

namespace rz
{

void CCmdProcessor::Insert(const char *asCmd)
{
};

void CCmdProcessor::Append(const char *asCmd)
{
};

void CCmdProcessor::ExecText(const char *asCmd)
{
	mCoreEnv.pLog->Debug("CCmdProcessor::ExecText(\"%s\")", asCmd);
	
	if(!strcmp(asCmd, "exit"))
		mpCore->RequestClose(); // hacky
	
	// TODO: command handlers
	//CCmdArgs Cmd(asCmd);
	//mpCmdHandler->Exec(Cmd);
};

void CCmdProcessor::Exec()
{
};

}; // namespace rz