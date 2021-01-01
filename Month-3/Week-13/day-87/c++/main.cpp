/**
 * DAY-87 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Help Dr. Banner.
 * 
 * @param n layers of Hulk feelings
 * @return Expression of Hulk's feelings
 */ 
std::string hulkFeel(const int n) {
    std::string feeling;
    
    const auto inception = [&n](const int x) { //capture n
        return std::string(x % 2 == 0 ? "I hate " : "I love ") + (x >= (n - 1) ? "it" : "that ");
    };

    for (int i = 0; i < n; i++) {
        feeling += inception(i);
    }

    return feeling;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(hulkFeel(1) == "I hate it");
    CHECK(hulkFeel(2) == "I hate that I love it");
    CHECK(hulkFeel(3) == "I hate that I love that I hate it");
}