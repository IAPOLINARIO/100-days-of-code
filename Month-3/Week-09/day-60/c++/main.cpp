/**
 * DAY-60 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * A Game of Threes
 * 
 * @param n The number at which the game starts
 * 
 * @return String with list of valid steps that must be taken to play the game. 
 * Each step is represented by the number you start at, followed by either -1 or 1 (if you are adding/subtracting 1 before dividing), or 0 (if you are just dividing). 
 * The last line should simply be 1.
 */ 
std::string gameOfThrees(int n, std::string steps = "") {
    steps += "\n" + std::to_string(n);

    if (n == 1) {
        std::cout << steps << std::endl; //print result
        return steps;
    }    

    if (n % 3 == 0) {                
        steps += " 0";        
    } else {
        if ((n + 1) % 3 == 0) {
            steps += " 1";
            n += 1;
        } else {
            steps += " -1";
            n -= 1;
        }
    }

    n /= 3;

    return gameOfThrees(n, steps);    
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(gameOfThrees(100) == 
R"(
100 -1
33 0
11 1
4 -1
1)");

}





