/**
 * DAY-18 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  Number of additional paths ahead.
 *  @param step current step of the path
 *  @param maxM M component of grid m x n
 *  @param maxM N component of grid m x n
 *  @return number of additional paths
 */
int additionalPaths(int step[2], int maxM, int maxN) {
    int step1[2] = {step[0] + 1, step[1]};
    int step2[2] = {step[0], step[1] + 1};
    return ((step[0] + 1 < maxM && step[1] + 1 < maxN) ? 1 + additionalPaths(step1, maxM, maxN) + additionalPaths(step2, maxM, maxN) : (step[0] + 1 < maxM) ? additionalPaths(step1, maxM, maxN) : (step[1] + 1 < maxN) ? additionalPaths(step2, maxM, maxN) : 0);
}

/**
 *  How many possible unique paths are there?
 *  @param m component of grid m x n
 *  @param n component of grid m x n
 *  @return number of unique paths
 */
int uniquePaths(int m, int n) 
{           
    int step[2] = {0, 0};        
    return additionalPaths(step, m, n) + 1;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{       
    CHECK(uniquePaths(3, 2) == 3);
    CHECK(uniquePaths(3, 3) == 6);
    CHECK(uniquePaths(7, 3) == 28);    
}