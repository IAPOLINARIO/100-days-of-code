/**
 * DAY-10 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 *
 * @param number of values to store
 * @return number of structurally unique BST's (binary search trees) that store values 1 ... n
 */
int uniqueBST(int n)
{    
    if (n <= 1) {
        return 1;
    } else {
        int r = 0;
        for (int i = 1; i <= n; i++) {
            r += uniqueBST(i - 1) * uniqueBST(n - i);
        }
        return r;
    }
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(uniqueBST(1) == 1);
    CHECK(uniqueBST(2) == 2);
    CHECK(uniqueBST(3) == 5);
    CHECK(uniqueBST(4) == 14);
}