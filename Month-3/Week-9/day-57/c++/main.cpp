/**
 * DAY-57 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Magic Sigil Generator
 * @param input text
 * @return The Magic Sigil
 */ 
std::string sigilize(std::string text) {
    const auto isVowel = [&](char x) { return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') ? true : false; };    
    std::string r;    
    std::map<char, bool> rMap;
    for (int i = text.size() - 1; i >= 0; i--) {
        char x = tolower(text[i]);
        if (!(isVowel(x) || x == ' ' || rMap.find(x) != rMap.end())) {
            rMap[x] = true;
            r += toupper(x);    
        }        
    }
    std::reverse(r.begin(), r.end());
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(sigilize("i am healthy") == "MLTHY");
    CHECK(sigilize("I FOUND MY SOULMATE") == "FNDYSLMT");    
    CHECK(sigilize("I have a job I enjoy and it pays well") == "HVBJNDTPYSWL");
}



