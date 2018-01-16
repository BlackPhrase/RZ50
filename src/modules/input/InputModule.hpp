#pragma once

#include "core/IModule.hpp"

namespace rz
{

class CInputModule final : public IModule
{
public:
	CInputModule(const IServiceLocator &aCoreEnv) : mCoreEnv(aCoreEnv){}
	~CInputModule() = default;
	
	bool Init(const IServiceLocator &aCoreEnv) override;
	void Shutdown() override;
	
	const char *GetModuleName() const override {return "Input";}
private:
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz