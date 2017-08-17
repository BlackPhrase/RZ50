#include <cstring>
#include "CmdExecutor.hpp"
#include "Core.hpp"

namespace rz
{

CCmdExecutor::CCmdExecutor(CCore *apCore) : mpCore(apCore){}
CCmdExecutor::~CCmdExecutor() = default;

void CCmdExecutor::Init()
{
	//ICmdHandler *pDefaultCmdHandler = new CDefaultCmdHandler(mCoreEnv); // TODO: REV THIS
	//pDefaultCmdHandler->AddCommand();
	//mlstHandlers.push_back(pDefaultCmdHandler);
};

void CCmdExecutor::AddHandler(ICmdHandler *apHandler)
{
	// lock or atomic
	
	//mlstHandlers.push_back(apHandler);
};

void CCmdExecutor::RemoveHandler(ICmdHandler *apHandler)
{
	// lock or atomic
	
	// remove the specified handler from the list (or mark it for remove?)
	
	//mlstHandlers.erase(apHandler);
};

bool CCmdExecutor::ExecArgs(const ICmdArgs &aArgs)
{
	//for(auto It : mlstHandlers)
		//if(!strcmp(It->GetName(), aArgs.GetByIndex(0)))
			//if(It->HandleCmd(aArgs))
				//return true;
	
	//mCoreEnv.pLog->Error("No valid handler for command \"%s\"", sCmdName.c_str());
	return false;
};

bool CCmdExecutor::ExecString(const char *asText)
{
	if(!strcmp(asText, "exit"))
	{
		mpCore->RequestClose(); // TODO: REMOVE THIS
		return true;
	};
	
	return false;
};

}; // namespace rz