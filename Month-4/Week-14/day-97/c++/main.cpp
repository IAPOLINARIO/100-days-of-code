/**
 * DAY-97 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * What is the minimum number of steps the elephant needs to take to reach his friend's house?
 
 * @param target Elephant's friend position
 * @return Minimum number of steps
 */ 
int elephantSteps(const int target) {    
    const std::array<int, 5> ELEPHANT_SPEED = {5, 4, 3, 2, 1};
    int position = 0;
    int steps = 0;

    while (position < target) {
        for (auto &s : ELEPHANT_SPEED) {
            if ((position + s) <= target) {
                position += s;
                steps++;
                break;
            }
        }
    }

    return steps;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(elephantSteps(5) == 1);
    CHECK(elephantSteps(12) == 3);
}











