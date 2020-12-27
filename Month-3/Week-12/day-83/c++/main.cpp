/**
 * DAY-83 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <tuple>

/**
 * Bathroom Stalls.
 * 
 * @param n Number of stalls
 * @param k Number of people
 * @return std::array<int, 2>, as index = 0 -> max(LS, RS), index = 1 -> min(LS, RS), as calculated by the last person to enter the bathroom for their chosen stall
 */ 
std::array<int, 2> bathroomStalls(const int n, const int k) {    
    if (n <= 0 || k <= 0 || k > n) {
        return {-1, -1}; //invalid input
    }    
    std::vector<std::tuple<bool, int, int>> stalls; //setup the stalls
    for (int i = 0; i < n; i++) {
        stalls.push_back(std::make_tuple(true, i, n - i - 1)); //tuple: empty?, min(LS), max(LR)
    }            
    int o;
    for (int p = 0; p < k; p++) { //check stall options for each person
        o = -1;
        for (int i = 0; i < n; i++) { //stalls
            if (std::get<0>(stalls[i])) { //is empty?
                const auto oMin = (o != -1) ? std::min(std::get<1>(stalls[o]), std::get<2>(stalls[o])) : -1;
                const auto sMin = std::min(std::get<1>(stalls[i]), std::get<2>(stalls[i]));
                if (sMin > oMin || (sMin == oMin && (std::max(std::get<1>(stalls[i]), std::get<2>(stalls[i])) > std::max(std::get<1>(stalls[o]), std::get<2>(stalls[o]))))) {
                    o = i;
                }
            }
        }        
        std::get<0>(stalls[o]) = false; ////update stalls. This one is not empty anymore
        for (int i = 0; i < n; i++) {
            std::array<int, 2> empties = {0, 0}; //for left and right sides
            for (int j = i - 1; j >= 0 && std::get<0>(stalls[j]); j--) {
                empties[0]++;
            }                        
            for (int j = i + 1; j < n && std::get<0>(stalls[j]); j++) {
                empties[1]++;
            }
            std::get<1>(stalls[i]) = empties[0];
            std::get<2>(stalls[i]) = empties[1];
        }        
    }    
    return {std::max(std::get<1>(stalls[o]), std::get<2>(stalls[o])), std::min(std::get<1>(stalls[o]), std::get<2>(stalls[o]))};
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(bathroomStalls(4, 2) == std::array<int, 2>{1, 0});    
    CHECK(bathroomStalls(5, 2) == std::array<int, 2>{1, 0});
    CHECK(bathroomStalls(6, 2) == std::array<int, 2>{1, 1});
    CHECK(bathroomStalls(1000, 1000) == std::array<int, 2>{0, 0});
    CHECK(bathroomStalls(1000, 1) == std::array<int, 2>{500, 499});
    CHECK(bathroomStalls(6, 7) == std::array<int, 2>{-1, -1}); //invalid input
}