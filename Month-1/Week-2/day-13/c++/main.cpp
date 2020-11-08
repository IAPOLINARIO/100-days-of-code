/**
 * DAY-13 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  Check if your bags can carry the items
 *  @param weights of each item
 *  @param bags number of bags (each bag supports 10kg)
 *  @return true if your bags can carry the items
 */
bool canFit(std::vector<int> weights, int bags)
{    
    const int BAG_CAPACITY = 10;
    int bagsUsed = 0;
    int totalBagWeight = 0;
    int pendingWeight = 0;

    for (auto &w : weights) {
        totalBagWeight += w;
        if (totalBagWeight >= BAG_CAPACITY) {
            pendingWeight += totalBagWeight - BAG_CAPACITY;
            bagsUsed++;
            totalBagWeight = 0;
        }
    }

    bagsUsed = (pendingWeight > 0) ? bagsUsed + ceil( static_cast<float>(pendingWeight) / BAG_CAPACITY ) : bagsUsed;
    return bagsUsed <= bags;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(canFit({5}, 1) == true);    
    CHECK(canFit({5, 6}, 1) == false);    
    CHECK(canFit({2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2}, 4) == true);    
    CHECK(canFit({2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2}, 4) == false);    
    CHECK(canFit({2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2}, 5) == true);    
    CHECK(canFit({8, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}, 5) == false);    
    CHECK(canFit({4, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}, 6) == true);    
}