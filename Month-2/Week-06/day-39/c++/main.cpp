/**
 * DAY-39 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * How many games can you buy during the Halloween Sale?
 * @param p Normal price of games
 * @param d The discount
 * @param m Minimum value per game
 * @param s The budget
 * @return The number of games you can buy
 */ 
int howManyGames(int p, int d, int m, int s) {
    int sum = 0;    
    for (int c = 0;; c++) {
        int price = p - (c * d);
        if (price < m) {
            price = m;
        }        
        sum += price;
        if (sum > s)  {
            return c;
        }
    }    
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(howManyGames(20, 3, 6, 80) == 6);
}