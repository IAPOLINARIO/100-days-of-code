/**
 * DAY-38 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Determine the most expensive computer keyboard and USB drive that can be purchased with a give budget.
 * @param keyboards Prices of keyboards
 * @param drives Prices of USB drives
 * @param Cost to buy the items, -1 if it is not possible to buy both
 */ 
int getMoneySpent(std::vector<int> keyboards, std::vector<int> drives, int b, int r = -1) {    
    for (auto &k : keyboards) for (auto &d : drives) r = (k + d) > r && (k + d) <= b ? (k + d) : r;
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(getMoneySpent({40,50,60},{5,8,12}, 60) == 58);
    CHECK(getMoneySpent({40,50,60},{18,19,20}, 57) == -1);
}