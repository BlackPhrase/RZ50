#include "core/CoreTypes.hpp"
#include "DefaultCmdHandler.hpp"

namespace rz
{

void CDefaultCmdHandler::HandleCmd(const char *asText)
{
	string sCmdText(asText);
	auto nPos = sCmdText.find_first_of(" ");
	string sCmdName = sCmdText.substr(0, nPos);
	
	for(auto It : mlstCmds)
		if(!strcmp(It->sName, sCmdName.c_str()))
		{
			It->fnCallback();
			return;
		};
	
	//mCoreEnv.pLog->Error("No valid handler for command \"%s\"", sCmdName.c_str());
};

void CDefaultCmdHandler::AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
{
	//mlstCmds.emplace_back(asName, afnCallback, asDesc);
	mlstCmds.push_back(new CCmd(asName, afnCallback, asDesc));
};

}; // namespace rz