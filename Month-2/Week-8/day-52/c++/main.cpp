/**
 * DAY-52 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Given a 2D array of some suspended blocks (represented as hastags), 
 * return another 2D array which shows the end result once gravity is switched on.
 * 
 * @param w 2D array of some suspended blocks (represented as hastags)
 * @return 2D array which shows the end result once gravity is switched on
 */ 
std::vector<std::vector<char>> switchGravityOn(std::vector<std::vector<char>> w) {    
    for (int y = w.size() - 2; y >= 0; y--) {
        for (int x = 0; x < w[0].size(); x++) {
            for (int drop = y; drop < (w.size() - 1) && w[drop][x] == '#' && w[drop + 1][x] == '-'; drop++) {
                w[drop + 1][x] = '#';
                w[drop][x] = '-';
            }            
        }
    }
    return w;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(switchGravityOn({{'-', '#', '#', '-'},
                           {'-', '-', '-', '-'},
                           {'-', '-', '-', '-'},
                           {'-', '-', '-', '-'}}) == std::vector<std::vector<char>>{{'-', '-', '-', '-'},
                                                                                    {'-', '-', '-', '-'},
                                                                                    {'-', '-', '-', '-'},
                                                                                    {'-', '#', '#', '-'}});
    CHECK(switchGravityOn({{'-', '#', '#', '-'},
                           {'-', '-', '#', '-'},
                           {'-', '-', '-', '-'},
                           {'-', '-', '-', '-'}}) == std::vector<std::vector<char>>{{'-', '-', '-', '-'},
                                                                                    {'-', '-', '-', '-'},
                                                                                    {'-', '-', '#', '-'},
                                                                                    {'-', '#', '#', '-'}});
    CHECK(switchGravityOn({{'-', '#', '#', '#', '#', '-'},
                           {'#', '-', '-', '#', '#', '-'},
                           {'-', '#', '-', '-', '-', '-'},
                           {'-', '-', '-', '-', '-', '-'}}) == std::vector<std::vector<char>>{{'-', '-', '-', '-', '-', '-'},
                                                                                              {'-', '-', '-', '-', '-', '-'},
                                                                                              {'-', '#', '-', '#', '#', '-'},
                                                                                              {'#', '#', '#', '#', '#', '-'}});
}