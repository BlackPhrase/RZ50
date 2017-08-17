#pragma once

#include <list>

namespace rz
{

class CCore;

struct ICmdArgs;

struct ICmdHandler;
using tCmdHandlerList = std::list<ICmdHandler*>;

class CCmdExecutor final
{
public:
	CCmdExecutor(CCore *apCore);
	~CCmdExecutor();
	
	void Init();
	
	//void AddHandler(const ICmdHandler &aHandler) override;
	void AddHandler(ICmdHandler *apHandler);
	void RemoveHandler(ICmdHandler *apHandler);
	
	bool ExecArgs(const ICmdArgs &aArgs);
	bool ExecString(const char *asText); // ExecText; remove?
private:
	tCmdHandlerList mlstHandlers;
	
	CCore *mpCore{nullptr};
};

}; // namespace rz