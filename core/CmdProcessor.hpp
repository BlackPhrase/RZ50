#pragma once

#include "core/ICmdProcessor.hpp"

namespace rz
{

class CCmdProcessor : public ICmdProcessor
{
public:
	CCmdProcessor() = default;
	~CCmdProcessor() = default;
	
	void Insert(const char *asCmd);
	
	void Append(const char *asCmd);
	
	void Exec();
private:
};

}; // namespace rz