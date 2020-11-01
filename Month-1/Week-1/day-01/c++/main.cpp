/**
 * DAY-01 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

int calcAge(int years) {
    return years * 365;
}

/**
 * TEST
 */
TEST_CASE("calcAge TEST") {    
    CHECK(calcAge(0) == 0);
    CHECK(calcAge(20) == 7300);
    CHECK(calcAge(65) == 23725);    
}