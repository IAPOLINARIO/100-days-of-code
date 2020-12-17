/**
 * DAY-44 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Get the Maximum Edge of a Triangle.
 * @param a Side A
 * @param b Side B
 * @return Maximum Edge of a Triangle
 */ 
int nextEdge(int a, int b) {
    return a + b - 1;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(nextEdge(8, 10) == 17);
    CHECK(nextEdge(5, 7) == 11);
    CHECK(nextEdge(9, 2) == 10);
}