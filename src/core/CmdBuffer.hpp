#pragma once

#include <deque>
#include <list>
#include "core/CoreTypes.hpp"

namespace rz
{

class CCmdExecutor;

using tCmdTextQue = std::deque<string>;

class CCmdBuffer final
{
public:
	CCmdBuffer(CCmdExecutor *apExecutor);
	~CCmdBuffer();
	
	void InsertText(const char *asCmd);
	void AppendText(const char *asCmd);
	
	void Exec();
private:
	tCmdTextQue mCmdQue; //mTextQue
	
	CCmdExecutor *mpExecutor{nullptr};
};

}; // namespace rz