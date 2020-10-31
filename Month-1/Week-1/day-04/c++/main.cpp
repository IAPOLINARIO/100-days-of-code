/**
 * DAY-04 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <vector>

/**
 * Calculate total number of progress days
 *
 * @param vector of miles run every Saturday
 * @return int of total number of progress days
 */
int progressDays(std::vector<int> miles) {
    int progressDays = 0;    
    for (int i = 1; i < miles.size(); i++) {
        miles[i] > miles[i - 1] ? progressDays++ : 0;
    }
    return progressDays;
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(progressDays({3, 4, 1, 2}) == 2);
    CHECK(progressDays({10, 11, 12, 9, 10}) == 3);
    CHECK(progressDays({6, 5, 4, 3, 2, 9}) == 1);
    CHECK(progressDays({9, 9}) == 0);
    CHECK(progressDays({7}) == 0);
    CHECK(progressDays({}) == 0);
}