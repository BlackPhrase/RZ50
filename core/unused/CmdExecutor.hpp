#pragma once

#include <list>

namespace rz
{

struct ICmdArgs;

struct ICmdHandler;
using tCmdHandlerList = std::list<ICmdHandler*>;

class CCmdExecutor final
{
public:
	CCmdExecutor() = default;
	~CCmdExecutor() = default;
	
	void Init();
	
	//void AddHandler(const ICmdHandler &aHandler) override;
	void AddHandler(ICmdHandler *apHandler);
	void RemoveHandler(ICmdHandler *apHandler);
	
	bool ExecArgs(const ICmdArgs &aArgs);
private:
	tCmdHandlerList mlstHandlers;
};

}; // namespace rz