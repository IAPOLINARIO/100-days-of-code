/**
 * DAY-64 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Outputs the first recurring character in a string.
 * @param word as string
 * @return the first recurring character
 */ 
char firstRecurringChar(std::string word) {
    std::pair<char, int> r = std::make_pair(' ', -1);    
    for (size_t i = 0; i < word.size(); i++) {        
        for (size_t j = i + 1; j < word.size(); j++) {
            if (word[j] == word[i] && (j < r.second || r.second == -1)) {                                
                r.first = word[i];
                r.second = j;                
            }
        }        
    }    
    return r.first;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(firstRecurringChar("ABCDEBC") == 'B');
    CHECK(firstRecurringChar("AXCDEBCX") == 'C');
}

