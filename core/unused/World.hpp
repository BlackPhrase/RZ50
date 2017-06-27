#pragma once

#include <vector>

namespace rz
{

struct IEntity;
using tEntityVec = std::vector<IEntity*>;

class CWorld
{
public:
	CWorld() = default;
	~CWorld() = default;
	
	void Update();
	
	void SetEntityActive(IEntity &aEntity, bool abActive);
private:
	tEntityVec mvEntities;
	tEntityVec mvActiveEntities;
};

}; // namespace rz