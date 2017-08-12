#include "CmdBuffer.hpp"
#include "CmdExecutor.hpp"

namespace rz
{

CCmdBuffer::CCmdBuffer(CCmdExecutor *apExecutor) : mpExecutor(apExecutor){}
CCmdBuffer::~CCmdBuffer() = default;

void CCmdBuffer::InsertText(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdQue.emplace_front(asCmd);
};

void CCmdBuffer::AppendText(const char *asCmd)
{
	// TODO: lock or atomic
	
	mCmdQue.emplace_back(asCmd);
};

void CCmdBuffer::Exec()
{
	// TODO: lock or atomic?
	
	while(!mCmdQue.empty())
	{
		//mpExecutor->ExecText(mCmdQue.front().c_str());
		mCmdQue.pop_front();
	};
};

}; // namespace rz