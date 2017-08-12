#include "World.hpp"
#include "entity/IEntity.hpp"

namespace rz
{

void CWorld::Update()
{
	for(auto It : mvActiveEntities)
		It->Update();
};

}; // namespace rz