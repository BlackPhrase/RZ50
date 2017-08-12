#include "core/CoreTypes.hpp"
#include "DefaultCmdHandler.hpp"

namespace rz
{

bool CDefaultCmdHandler::HandleCmd(const char *asText)
{
	string sCmdText(asText);
	auto nPos = sCmdText.find_first_of(" ");
	string sCmdName = sCmdText.substr(0, nPos);
	
	if(!strcmp(sCmdName.c_str(), "exit"))
		return true;
	
	return false;
};

}; // namespace rz