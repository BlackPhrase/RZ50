/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "CmdLine.hpp"

namespace rz
{

CCmdLine::CCmdLine(const char *asCmdLine)
{
};

CCmdLine::CCmdLine(int argc, char **argv)
{
};

const char *CCmdLine::GetArgValue(int anIndex) const
{
	return "";
};

bool CCmdLine::HasArg(const char *asName) const
{
	return false;
};

uint CCmdLine::GetArgCount() const
{
	return 0;
};

}; // namespace rz