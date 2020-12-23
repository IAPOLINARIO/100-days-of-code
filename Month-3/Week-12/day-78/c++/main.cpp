/**
 * DAY-78 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * A number without numbers - 2021
 */
TEST_CASE("Tests")
{
    CHECK('z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'z' + 'E' == 2021);
}