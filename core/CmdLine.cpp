#include "CmdLine.hpp"

namespace rz
{

CCmdLine::CCmdLine(const char *asCmdLine)
{
};

CCmdLine::CCmdLine(int argc, char **argv)
{
};

const char *CCmdLine::GetArgValue(int anIndex) const
{
	return "";
};

bool CCmdLine::HasArg(const char *asName) const
{
	return false;
};

uint CCmdLine::GetArgCount() const
{
	return 0;
};

}; // namespace rz