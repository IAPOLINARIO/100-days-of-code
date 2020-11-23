/**
 * DAY-25 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <numeric> //for std::accumulate

/** 
 * Determine if the coins can be distributed equally or not. 
 * @param coins list of coins
 * @param divideBy number of children (default 3)
 * @return true if each son receives the same amount of money, otherwise return false.
 */ 
bool coinsDiv(std::vector<unsigned int> coins, unsigned int divideBy = 3) {    
    auto total = std::accumulate(coins.begin(), coins.end(), decltype(coins)::value_type(0));
    
    if (total % divideBy != 0) {
        return false;
    }

    auto target = (total / divideBy);

    for (int divCount = 0; divCount < divideBy; divCount++) {            
        std::vector<int> options; 
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= target) {
                options.push_back(coins[i]);
            }
        }

        std::sort(options.begin(), options.end());

        int sum = 0;
        for (int o = options.size() - 1; o >= 0; o--) {
            if ((options[o] + sum) <= target) {                
                sum += options[o];
                auto it = std::find(coins.begin(), coins.end(), options[o]);
                if (it != coins.end()) {
                    coins.erase(it);
                }
            }
        } 
        
        if (sum != target) {
            return false;
        }
    }

    return true;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{           
  CHECK(coinsDiv({1, 2, 3, 2, 2, 2, 3}) == true);
  CHECK(coinsDiv({5, 3, 10, 1, 2}) == false);
  CHECK(coinsDiv({2, 4, 3, 2, 4, 9, 7, 8, 6, 9}) == true);
  CHECK(coinsDiv({1, 1, 1, 1, 1, 1}) == true);
  CHECK(coinsDiv({10, 1, 1}) == false);
}