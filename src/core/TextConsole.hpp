#pragma once

#include "ITextConsole.hpp"

namespace rz
{

class CTextConsole : public ITextConsole
{
public:
	CTextConsole() = default;
	virtual ~CTextConsole() = default;
};

}; // namespace rz