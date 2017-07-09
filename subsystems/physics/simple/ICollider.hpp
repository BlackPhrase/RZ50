#pragma once

namespace rz
{

struct ICollider
{
	virtual TIntersectData Intersect(const ICollider &aOther) = 0;
};

}; // namespace rz