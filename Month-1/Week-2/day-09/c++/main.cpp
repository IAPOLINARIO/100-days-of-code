/**
 * DAY-09 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Given n integers (NEGATIVE NUMBERS ARE OK) representing an elevation map where the width of each 
 * bar is 1, compute how much water it can trap after raining.
 *
 * @param Elevation map
 * @return int How much water it can trap after raining.
 */
int trappedRainWater(std::vector<int> em) {
    int r = 0;
    int top = 0;
    int acc = 0;    
    for (int i = 0; i < em.size(); i++) {
        if (em[i] >= top) {
            int highestNext = 0;
            for (int x = i + 1; x < em.size(); x++) {
                highestNext = em[x] > highestNext ? em[x] : highestNext;
                if (highestNext >= em[i]) {
                    highestNext = em[i];
                    break;
                }
            }
            top = highestNext;
            if (acc > 0) {
                r += acc;
                acc = 0;
            }
        }
        acc = em[i] < top ? acc + top - em[i] : acc;
    }
    return r;   
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(trappedRainWater(std::vector<int>({0,1,0,2,1,0,1,3,2,1,2,1})) == 6);
    CHECK(trappedRainWater(std::vector<int>({4,2,0,3,2,5})) == 9);
    CHECK(trappedRainWater(std::vector<int>({3,2,1,0,2})) == 3);  
    CHECK(trappedRainWater(std::vector<int>({0,0,1,3,2,1,1,0,3,0,1})) == 9);            
    CHECK(trappedRainWater(std::vector<int>({0,0,1,3,2,1,1,0,3,-1,1})) == 10);      
}