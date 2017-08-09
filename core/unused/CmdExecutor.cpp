#include "CmdExecutor.hpp"

namespace rz
{

void CCmdExecutor::Init()
{
	ICmdHandler *pDefaultCmdHandler = new CDefaultCmdHandler(mCoreEnv); // TODO: REV THIS
	//pDefaultCmdHandler->AddCommand();
	mlstHandlers.push_back(pDefaultCmdHandler);
};

void CCmdExecutor::AddHandler(ICmdHandler *apHandler)
{
	// lock or atomic
	
	mlstHandlers.push_back(apHandler);
};

void CCmdExecutor::RemoveHandler(ICmdHandler *apHandler)
{
	// lock or atomic
	
	// remove the specified handler from the list (or mark it for remove?)
	
	mlstHandlers.erase(apHandler);
};

bool CCmdExecutor::ExecArgs(const ICmdArgs &aArgs)
{
	for(auto It : mlstHandlers)
		if(!strcmp(It->GetName(), aArgs.GetByIndex(0)))
			if(It->HandleCmd(aArgs))
				return true;
	
	//mCoreEnv.pLog->Error("No valid handler for command \"%s\"", sCmdName.c_str());
	return false;
};

}; // namespace rz