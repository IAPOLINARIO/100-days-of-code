/**
 * DAY-42 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Given n and p, find and return the minimum number of pages that must be turned in order to arrive at page p.
 * When they open the book, page 1 is always on the right side. The last page may only be printed on the front, given the length of the book.
 * @param n Number of pages
 * @param p Target page
 * @return Minimum number of pages to turn
 */ 
int minPages(int n, int p) {    
    if (n < p) { //input validation
        return -1;
    }

    p = (p % 2 != 0) ? --p : p;
    n = (n % 2 != 0) ? --n : n;    

    int front = p / 2;
    int back = (n - p) / 2;

    return front < back ? front : back;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(minPages(5, 3) == 1);
    CHECK(minPages(21, 19) == 1);
    CHECK(minPages(21, 18) == 1);
    CHECK(minPages(21, 17) == 2);
    CHECK(minPages(21, 16) == 2);
    CHECK(minPages(21, 15) == 3);
    CHECK(minPages(20, 15) == 3);
    CHECK(minPages(15, 6) == 3);
    CHECK(minPages(15, 5) == 2);
}