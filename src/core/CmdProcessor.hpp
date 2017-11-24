#pragma once

#include <memory>
#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

struct IServiceLocator;
class CCore;

class CCmdBuffer;
class CCmdExecutor;
class CCmdContainer;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const IServiceLocator &aCoreEnv);
	~CCmdProcessor();
	
	void Init(IServiceLocator &aCoreEnv, CCore *apCore);
	
	void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc) override;
	
	void BufferText(const char *asText, InsertMode aeMode) override;
	void ExecText(const char *asText) override;
	
	void ExecBuffer() override;
private:
	std::unique_ptr<CCmdBuffer> mpBuffer;
	std::unique_ptr<CCmdExecutor> mpExecutor;
	std::unique_ptr<CCmdContainer> mpContainer;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz