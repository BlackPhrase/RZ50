#pragma once

#include <list>
#include "core/ICmdProcessor.hpp"

namespace rz
{

struct CCmd
{
	CCmd(const char *asName, pfnCmdCallback afnCallback, const char *asDesc)
		: sName(asName), sDesc(asDesc), fnCallback(afnCallback){}

	const char *sName{""};
	const char *sDesc{""};

	pfnCmdCallback fnCallback{nullptr};
};

using tCmdList = std::list<CCmd*>;

class CCmdContainer final
{
public:
	CCmdContainer() = default;
	~CCmdContainer() = default;

	bool Add(const char *asName, pfnCmdCallback afnCallback, const char *asDesc = "");
	bool Remove(const char *asName);

	CCmd *Find(const char *asName) const;

	bool IsPresent(const char *asName) const;
private:
	tCmdList mlstCmds;
};

}; // namespace rz