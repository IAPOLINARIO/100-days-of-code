/**
 * DAY-43 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Get the area of the triangle.
 * @param b Base
 * @param h Height
 * @return Area of the triangle
 */ 
int triArea(int b, int h) {
    return b * h / 2;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(triArea(3, 2) == 3);
    CHECK(triArea(5, 4) == 10);
    CHECK(triArea(7, 4) == 14);
    CHECK(triArea(10, 10) == 50);
    CHECK(triArea(12, 11) == 66);
    CHECK(triArea(0, 60) == 0);
}