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