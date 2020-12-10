/**
 * DAY-55 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Create a function that keeps only strings with repeating identical characters
 * @param list of words
 * @return list of words with repeating identical characters
 */ 
std::vector<std::string> identicalFilter(std::vector<std::string> words) {
    std::vector<std::string> r = words;

    for (int i = 0; i < words.size(); i++) {
        std::sort(words[i].begin(), words[i].end());
        auto it = std::unique(words[i].begin(), words[i].end());        
        if (it - words[i].begin() != 1) {
            r.erase(r.begin() + i);
        }
    }
        
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(identicalFilter({"aaaaaa", "bc", "d", "eeee", "xyz"}) == std::vector<std::string>{"aaaaaa", "d", "eeee"});
    CHECK(identicalFilter({"88", "999", "22", "545", "133"}) == std::vector<std::string>{"88", "999", "22"});
    CHECK(identicalFilter({"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}) == std::vector<std::string>{});
}

