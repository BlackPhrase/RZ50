#pragma once

#include <list>

namespace rz
{

struct ILog;
struct TCoreEnv;

struct ISubSystem;
using tSubSystemList = std::list<ISubSystem*>;

class CSubSystemManager
{
public:
	CSubSystemManager() = default;
	~CSubSystemManager() = default;
	
	bool Init(const TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	bool Add(const ISubSystem &apSubSystem);
	
	ISubSystem *GetByName(const char *asName);
	//ISubSystem *GetByIndex(int anID);
private:
	tSubSystemList mlstSubSystems;
	
	const TCoreEnv *mpCoreEnv{nullptr};
	ILog *mpLog{nullptr};
};

}; // namespace rz