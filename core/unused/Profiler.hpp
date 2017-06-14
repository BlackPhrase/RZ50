#pragma once

#include "core/IEventSystem.hpp"

namespace rz
{

class CProfiler final : public IEventListener
{
public:
	CProfiler() = default;
	~CProfiler() = default;
	
	bool Init() override;
	void Shutdown() override;
	
	void Update() override;
	
	void OnEvent(const TEvent &aEvent) override;
private:
};

}; // namespace rz