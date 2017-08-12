#pragma once

#include <list>
#include "core/ISubSystemContainer.hpp"

namespace rz
{

struct TCoreEnv;

struct ISubSystem;
using tSubSystemList = std::list<ISubSystem*>;

class CSubSystemContainer : public ISubSystemContainer
{
public:
	CSubSystemContainer(const TCoreEnv &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CSubSystemContainer() = default;
	
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