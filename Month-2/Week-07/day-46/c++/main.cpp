/**
 * DAY-46 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Checks to see if it contains the following words or phrases:
 * - "anime"
 * - "meme"
 * - "vines"
 * - "roasts"
 * - "Danny DeVito"
 *
 * @param content The content
 * @returns "NO!". Otherwise, return "Safe watching!"
 */ 
std::string preventDistractions(std::string content) {
    const std::string NO = "NO!";
    const std::string YES = "Safe watching!";
    const int BANNED_SIZE = 5;
    const std::string banned[BANNED_SIZE] = {"anime", "meme", "vines", "roasts", "Danny DeVito"};

    for (int i = 0; i < BANNED_SIZE; i++) {
        if (content.find(banned[i]) != std::string::npos) {
            return NO;
        }
    }

    return YES;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(preventDistractions("vines that butter my eggroll") == "NO!");
    CHECK(preventDistractions("Hot pictures of Danny DeVito") == "NO!");
    CHECK(preventDistractions("How to ace BC Calculus in 5 Easy Steps") == "Safe watching!");
}