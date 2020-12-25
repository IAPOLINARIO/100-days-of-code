/**
 * DAY-76 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  The Cake Thief
 *  @param cakes Vecotr of cake types (as a std::pair<weight, price>)
 *  @param bagCapacity The bag capacity
 *  @return The maximum monetary value the duffel bag can hold.
 */
int maxDuffelBagValue(std::vector<std::pair<int, int>> cakes, int bagCapacity) { 
    int value = 0;           
    std::sort(cakes.begin(), cakes.end(), [&](std::pair<int, int> a, std::pair<int, int> b) { return ((double) a.second / a.first) > ((double) b.second / b.first); });    
    for (auto &o : cakes) {
        while ((bagCapacity - o.first) >= 0) {
            bagCapacity -= o.first;
            value += o.second;
        }
    }     
    return value;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(maxDuffelBagValue({std::make_pair(7, 160), std::make_pair(3, 90), std::make_pair(2, 15)}, 20) == 555);
    CHECK(maxDuffelBagValue({std::make_pair(3, 160), std::make_pair(7, 90), std::make_pair(1, 15)}, 20) == 990);
}