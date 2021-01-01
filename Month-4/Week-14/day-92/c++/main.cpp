/**
 * DAY-92 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * For how many hours can his candles light up the room if he acts optimally well?
 * Each candle burns for an hour.
 * 
 * @param startingCandles Starting candles
 * @param burnedCandlesToCreateNewOne Number of burned candles necessary to build a new one
 * @return Number of hours the candles light up the room
 */ 
int candlesDuration(int startingCandles, int burnedCandlesToCreateNewOne) {
    int r = startingCandles;
    int x;
    while ((x = startingCandles / burnedCandlesToCreateNewOne) > 0) {
        startingCandles = x;
        r += x;
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(candlesDuration(4, 2) == 7);
    CHECK(candlesDuration(6, 3) == 8);
}











