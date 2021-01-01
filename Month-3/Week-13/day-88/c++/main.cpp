/**
 * DAY-88 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * What is the minimum number of bills Allen could receive after withdrawing his entire balance?
 * @param n Balance
 * @return Minimum number of bills
 */ 
int withdrawBills(const int n) {
    const std::array<int, 5> DOLLAR_BILLS = {100, 20, 10, 5, 1};

    int need = 0;
    int value = 0;
    while (value < n) {
        for (size_t i = 0; i < DOLLAR_BILLS.size(); i++) {
            if ((value + DOLLAR_BILLS[i]) <= n) {
                value += DOLLAR_BILLS[i];
                need++;
                break;
            }
        }
    }

    return need;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(withdrawBills(125) == 3);
    CHECK(withdrawBills(43) == 5);
    CHECK(withdrawBills(1000000000) == 10000000);
}