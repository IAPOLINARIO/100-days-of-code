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
bool canFit(std::vector<int> weights, int bags) {    
    const int BAG_CAPACITY = 10;    
    for (bags = bags; bags >= 0 && weights.size() > 0; bags--) {    
        int bagWeight = weights[0];
        weights.erase(weights.begin());        
                               
        std::vector<int> options;        
        for (int w = 0; w < weights.size(); w++) {
            if ((weights[w] + bagWeight) <= BAG_CAPACITY) {                
                options.push_back(weights[w]);
            }
        }

        std::sort(options.begin(), options.end());

        for (int o = options.size() - 1; o >= 0; o--) {
            if ((options[o] + bagWeight) <= BAG_CAPACITY) {                
                bagWeight += options[o];
                auto it = std::find(weights.begin(), weights.end(), options[o]);
                if (it != weights.end()) {
                    weights.erase(it);
                }
            }
        } 
    }      
    return bags >= 0;
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
    CHECK(canFit({4, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}, 6) == false);
    CHECK(canFit({2, 7, 1, 6, 3, 4, 7, 8, 8, 7}, 6) == true);
    CHECK(canFit({8, 3, 7, 7, 3, 4, 4, 1, 2, 2, 8}, 5) == true);        
}