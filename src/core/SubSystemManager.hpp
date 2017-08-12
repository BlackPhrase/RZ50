#pragma once

#include <list>
#include "core/ISubSystemManager.hpp"

namespace rz
{

struct TCoreEnv;

struct ISubSystem;
using tSubSystemList = std::list<ISubSystem*>;

class CSubSystemManager : public ISubSystemManager
{
public:
	CSubSystemManager(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CSubSystemManager() = default;
	
	bool Init(TCoreEnv &aCoreEnv);
	void Shutdown();
	
	void Update();
	
	bool Add(const ISubSystem &apSubSystem);
	//void Remove(const ISubSystem &aSubSystem);
	
	ISubSystem *GetByName(const char *asName) const;
	//ISubSystem *GetByIndex(int anID);
private:
	tSubSystemList mlstSubSystems;
	
	const TCoreEnv &mCoreEnv;
};

}; // namespace rz