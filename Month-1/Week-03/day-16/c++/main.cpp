/**
 * DAY-16 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  Check if you can win a Nim Game playing optimally
 *  @param n stones on the heap 
 *  @return true if you can win
 */
bool canWinNim(int n)
{    
    return n % 4 != 0;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{       
    CHECK(canWinNim(1) == true);
    CHECK(canWinNim(4) == false);
    CHECK(canWinNim(5) == true);
    CHECK(canWinNim(7) == true);
    CHECK(canWinNim(8) == false);    
    CHECK(canWinNim(10) == true);
    CHECK(canWinNim(122) == true);
    CHECK(canWinNim(759) == true);
    CHECK(canWinNim(1500) == false);
}
