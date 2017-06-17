#include <cstring>
#include "CmdProcessor.hpp"
#include "Core.hpp"

namespace rz
{

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

void CCmdProcessor::ExecText(const char *asCmd)
{
	// TODO: lock or atomic?
	
	mCoreEnv.pLog->Debug("CCmdProcessor::ExecText(\"%s\")", asCmd);
	
	if(!strcmp(asCmd, "exit"))
		mpCore->RequestClose(); // hacky
	
	// TODO: command handlers
	//CCmdArgs Cmd(asCmd);
	//mpCmdHandler->Exec(Cmd);
};

void CCmdProcessor::Exec()
{
	while(!mCmdBuffer.empty())
	{
		ExecText(mCmdBuffer.front().c_str());
		mCmdBuffer.pop_front();
	};
};

}; // namespace rz