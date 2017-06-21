/*
const char *reg_esp = "[ ,.\\t\\n;:]"; // List of separator characters.

// this can be done using raw string literals:
// const char *reg_esp = R"([ ,.\t\n;:])";

std::regex rgx(reg_esp); // 'regex' is an instance of the template class
                         // 'basic_regex' with argument of type 'char'.
std::cmatch match; // 'cmatch' is an instance of the template class
                   // 'match_results' with argument of type 'const char *'.
const char *target = "Unseen University - Ankh-Morpork";

// Identifies all words of 'target' separated by characters of 'reg_esp'.
if (std::regex_search(target, match, rgx)) {
    // If words separated by specified characters are present.

    const size_t n = match.size();
    for (size_t a = 0; a < n; a++) {
        std::string str (match[a].first, match[a].second);
        std::cout << str << "\n";
    }
}
*/