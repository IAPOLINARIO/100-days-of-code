/**
 * DAY-37 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Calculate the number of break records (high and low)
 * @param scores The scores in the same order as the games played
 * @return Number of records broken, index 0 is for high, index 1 is for low
 */ 
std::vector<int> breakingRecords(std::vector<int> scores) {
    std::vector<int> r = {0 ,0};
    if (scores.size() == 0) { //validate input
        return r; 
    }

    int high = scores[0];
    int low = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > high) {
            r[0] += 1;
            high = scores[i];
        } else {
            if (scores[i] < low) {
                r[1] += 1;
                low = scores[i];
            }
        }
    }
    
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(breakingRecords({10,5,20,20,4,5,2,25,1}) == std::vector<int>{2, 4});
    CHECK(breakingRecords({12,24,10,24}) == std::vector<int>{1, 1});
    CHECK(breakingRecords({}) == std::vector<int>{0, 0});
}