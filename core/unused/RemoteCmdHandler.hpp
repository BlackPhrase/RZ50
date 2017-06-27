#pragma once

namespace rz
{

// CNetworkCmdHandler
class CRemoteCmdHandler : public ICmdHandler
{
public:
	CRemoteCmdHandler() = default;
	~CRemoteCmdHandler() = default;
	
	bool HandleCmd(const char *asText) override;
private:
};

}; // namespace rz