/**
 * DAY-41 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Alex works at a clothing store. There is a large pile of socks that must be paired by color for sale. 
 * Given an array of integers representing the color of each sock, determine how many pairs of socks 
 * with matching colors there are.
 * @param socks
 * @return pair count
 */ 
int countPairs(std::vector<int> ar) {
    int r = 0;
    std::sort(ar.begin(), ar.end());
    for (int i = 1; i < ar.size(); i++) {
        if (ar[i] == ar[i - 1]) {
            r += 1;
            i += 1;
        }
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(countPairs({1,2,1,2,1,3,2}) == 2);
    CHECK(countPairs({1,1}) == 1);
    CHECK(countPairs({9999,1,1}) == 1);
    CHECK(countPairs({1,1,2}) == 1);
    CHECK(countPairs({1,1,2,2}) == 2);
    CHECK(countPairs({1,1,2,2,3}) == 2);
    CHECK(countPairs({1,1,2,2,3,3}) == 3);
    CHECK(countPairs({4,5,4,1,1,2,2,3,3}) == 4);
}