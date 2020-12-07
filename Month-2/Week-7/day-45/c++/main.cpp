/**
 * DAY-45 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Create a function to swap int variables X and Y 
 * without the use of an additional temporary storage variable using only XOR bitwise operations.
 * @param x X
 * @param y Y
 * @return The SUBTRACTION of swapped numbers by XOR bitwise operations.
 */ 
int XOR(int x, int y) {
    x = x xor y;
    y = x xor y;
    x = x xor y;
    return x - y;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(XOR(10, 41) == 31);
    CHECK(XOR(69, 420) == 351);
    CHECK(XOR(12345, 890412) == 878067);
    CHECK(XOR(2, 1) == -1);
}