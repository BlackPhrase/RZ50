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

#include "CmdParser.hpp"
#include "core/ICmdArgs.hpp"

namespace rz
{

const ICmdArgs &CCmdParser::Parse(const char *asText)
{
	// TODO
	
	// List of separator characters
	const char *sSeparators = "[ ,.\\t\\n;:]";

	// This can be done using raw string literals:
	// const char *sSeparators = R"([ ,.\t\n;:])";

	std::regex rgx(sSeparators);
	std::cmatch match;
	
	// Identifies all words of 'asText' separated by characters of 'sSeparators'.
	if(std::regex_search(asText, match, rgx))
	{
		// If words separated by specified characters are present

		const size_t n = match.size();
		for(size_t a = 0; a < n; ++a)
		{
			std::string str(match[a].first, match[a].second);
			std::cout << str << "\n";
		};
	};
};

}; // namespace rz