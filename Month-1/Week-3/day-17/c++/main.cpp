/**
 * DAY-17 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Switch lock of prison cells.
 * @param &pa prison arrangement
 */
void switchPrisonCells(std::vector<int> &pa) {
    for (int c = 0; c < pa.size(); c++) {
        pa[c] = pa[c] == 0 ? 1 : 0;
    }
}

/**
 *  How many prisoners can be freed?
 *  @param pa prison arrangement
 *  @return number of prisoners
 */
int freedPrisoners(std::vector<int> pa)
{       
    if (pa.size() == 0 || pa[0] == 0) {
        return 0;
    }

    switchPrisonCells(pa);
    int r = 1;
        
    for (int c = 1; c < pa.size(); c++) {
        if (pa[c] == 1) {
            switchPrisonCells(pa);
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
    CHECK(freedPrisoners({0}) == 0);
    CHECK(freedPrisoners({1, 1, 0, 0, 0, 1, 0}) == 4);
    CHECK(freedPrisoners({1, 1, 1}) == 1);
    CHECK(freedPrisoners({0, 0, 0}) == 0);
    CHECK(freedPrisoners({0, 1, 1, 1}) == 0);
}