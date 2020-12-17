/**
 * DAY-49 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Check if the swimming pool blueprint is legitimate. 
 * A pool is considered legitimate if it does not touch any of the four borders in this 2D array.
 * 
 * @param blueprint The swimming pool blueprint
 * @return true if it is legitimate
 */ 
bool isLegitimate(std::vector<std::vector<int>> blueprint) {
    for (int j = 0; j < blueprint.size(); j++) {
        for (int i = 0; i < blueprint[j].size(); i++) {
            if (j == 0 || j == blueprint.size() - 1 || i == 0 || i == blueprint[j].size() - 1) {
                if (blueprint[j][i] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 0, 0},
                      {0, 1, 1, 1, 1, 1, 0, 0},
                      {0, 1, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}}) == true);

    CHECK(
        isLegitimate({{1, 1, 0, 0, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {0, 1, 1, 1, 1, 1, 0, 0},
                      {0, 1, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}}) == false);         


    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}}) == true);                                         

    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}}) == false);                           

    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 1, 0}}) == false);                           

    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0}}) == false);                                                 

    CHECK(
        isLegitimate({{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 1, 1, 1, 1, 0},
                      {1, 1, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0}}) == false);                            
}