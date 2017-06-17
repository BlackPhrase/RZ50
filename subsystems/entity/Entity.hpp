#pragma once

#include "core/CoreTypes.hpp"
#include "IEntity.hpp"

namespace rz
{

class CEntity : public IEntity
{
public:
	CEntity() = default;
	~CEntity() = default;
	
	void SetName(const char *asName) override {msName = asName;}
	const char *GetName() const override {return msName.c_str();}
private:
	string msName{""};
};

}; // namespace rz