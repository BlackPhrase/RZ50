#pragma once

namespace rz
{

using pfnCmdCallback = void (*)();

struct ICmdProcessor
{
	///
	virtual void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc = "") = 0;
	
	/// BufferText insert modes
	enum class InsertMode : int
	{
		Insert = 0,
		Append
	};
	
	/// Insert the command text at the beginning of the buffer
	//virtual void InsertText(const char *asCmd) = 0;
	
	/// Append to the command text to the end of the buffer
	//virtual void AppendText(const char *asCmd) = 0;
	
	///
	virtual void BufferText(const char *asCmd, InsertMode aeMode) = 0;
	
	/// Execute the specified text immediately
	virtual void ExecText(const char *asText) = 0;
	
	/// Execute the command buffer immediately
	virtual void ExecBuffer() = 0;
};

}; // namespace rz