/**
 * DAY-95 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Count the minimum number of cashes to work, so that they can serve all visitors
 * @param timesOfVisit The times of visit of each client
 * @param Number of cashes
 */ 
int freeCash(std::vector<std::pair<int, int>> timesOfVisit) {
    int r = 1;
    
    std::map<std::pair<int, int>, int> v;
    for (auto &t : timesOfVisit) {        
        if (v.find(t) == v.end()) {
            v[t] = 1;
        } else {
            r++;
        }
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(freeCash({std::make_pair(8, 0), std::make_pair(8, 10), std::make_pair(8, 10), std::make_pair(8, 45)}) == 2);
    CHECK(freeCash({std::make_pair(0, 12), std::make_pair(10, 11), std::make_pair(22, 22)}) == 1);
}











