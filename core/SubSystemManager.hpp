#pragma once

#include <list>

struct ISubSystem;
using tSubSystemList = std::list<ISubSystem*>;

class CSubSystemManager
{
public:
	CSubSystemManager() = default;
	~CSubSystemManager() = default;
	
	bool Init();
	void Shutdown();
	
	void Update();
	
	bool Add(ISubSystem *apSubSystem);
	
	ISubSystem *GetByName(const char *asName);
	//ISubSystem *GetByIndex(int anID);
private:
	tSubSystemList mlstSubSystems;
};