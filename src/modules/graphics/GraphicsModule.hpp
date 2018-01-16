#pragma once

#include "core/IModule.hpp"

namespace rz
{

class CGraphicsModule final : public IModule
{
public:
	CGraphicsModule() = default;
	~CGraphicsModule() = default;
	
	bool Init(const IServiceLocator &aCoreEnv) override;
	void Shutdown() override;
	
	const char *GetModuleName() const override {return "Graphics";}
};

}; // namespace rz