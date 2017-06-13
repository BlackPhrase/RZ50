#pragma once

namespace rz
{

struct ICmdProcessor
{
	/// Insert the command text at the beginning of the buffer
	virtual void Insert(const char *asCmd) = 0;
	
	/// Append to the command text to the end of the buffer
	virtual void Append(const char *asCmd) = 0;
	
	/// Execute the specified text immediately
	virtual void ExecText(const char *asText) = 0;
	
	/// Execute the command buffer immediately
	virtual void Exec() = 0;
};

}; // namespace rz