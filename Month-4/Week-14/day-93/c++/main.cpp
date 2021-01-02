/**
 * DAY-93 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * What is the minimal number of moves to climb to the top of the stairs that satisfies the condition?
 * @param n Number of steps
 * @param m The condition: the number of moves need to be multiple of m
 * @param The minimal number of moves to climb to the top of the stairs or -1
 */ 
int climbMoves(int n, int m) {
    if (m > n) { 
        return -1;
    }
    
    if (n <= 0 || n > 10000 || m <= 1 || m > 10) { //constraints: (0 < n ≤ 10000, 1 < m ≤ 10)
        return -1; //invalid
    }

    auto steps = n / 2;
    if (n % 2 != 0) {
        steps++;
    }

    while ((steps % m != 0 && steps <= n)) {
        steps++;
    }
    if (steps > n) {
        steps = -1;
    }

    return steps;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(climbMoves(10, 2) == 6);
    CHECK(climbMoves(3, 5) == -1);
    CHECK(climbMoves(12, 2) == 6);
    CHECK(climbMoves(13, 2) == 8); //2 2 2 2 2 1 1 1
    CHECK(climbMoves(15, 2) == 8);
    CHECK(climbMoves(6, 1) == -1);
    CHECK(climbMoves(7, 1) == -1);
    CHECK(climbMoves(6, 4) == 4); //2 2 1 1
    CHECK(climbMoves(7, 4) == 4); //2 2 2 1 
    CHECK(climbMoves(8, 4) == 4); //2 2 2 2 
    CHECK(climbMoves(9, 4) == 8); //2 1 1 1 1 1 1 1
    CHECK(climbMoves(5, 3) == 3); //2 2 1
    CHECK(climbMoves(6, 3) == 3); //2 2 2
    CHECK(climbMoves(7, 3) == 6); //2 1 1 1 1 1
}











