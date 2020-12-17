/**
 * DAY-22 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest


float calcDestructionInFootballFields(float extension) {
    const float FOOTBALL_FIELD_SIZE = float(105 * 68) / 1000;
    return extension / FOOTBALL_FIELD_SIZE;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{                                  
    float r = calcDestructionInFootballFields(1034);

    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << r;
    CHECK(ss.str() == "144.82");   
}