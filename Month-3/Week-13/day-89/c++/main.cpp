/**
 * DAY-89 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Find the number of minutes before the New Year.
 * param h Hours (24h format)
 * param m Minutes
 * @return Number of minutes before the New Year
 */ 
int minutesBeforeNewYear(int h, int m) {
    if ((h == 0 && m == 0) || h < 0 || m < 0) {
        return 0;
    }

    return (24 - h) * 60 - m;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(minutesBeforeNewYear(23, 55) == 5);
    CHECK(minutesBeforeNewYear(23, 0) == 60);
    CHECK(minutesBeforeNewYear(0, 1) == 1439);
    CHECK(minutesBeforeNewYear(4, 20) == 1180);
    CHECK(minutesBeforeNewYear(23, 59) == 1);    
}