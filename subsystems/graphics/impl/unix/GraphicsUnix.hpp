#pragma once

#include "IGraphicsImpl.hpp"

namespace rz
{

class CGraphicsUnix final : public IGraphicsImpl
{
public:
	CGraphicsUnix() = default;
	~CGraphicsUnix() = default;
	
	bool OpenWindow() override;
	
	void ProcessEvents() override;
private:
};

}; // namespace rz