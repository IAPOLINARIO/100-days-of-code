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
    return (n % 3 == 0 && n % 2 != 0) || (n % 2 != 0 && (n + 2) % 3 == 0) || (n % 2 == 0 && (n + 1) % 3 == 0);
}

/**
 * Tests
 */
TEST_CASE("Tests")
{       
    CHECK(canWinNim(1) == true);      
    CHECK(canWinNim(2) == true);     
    CHECK(canWinNim(4) == false);        
    CHECK(canWinNim(5) == false);    
    CHECK(canWinNim(6) == false);    
    CHECK(canWinNim(7) == true);    
    CHECK(canWinNim(8) == true);    
    CHECK(canWinNim(9) == true);    
    CHECK(canWinNim(10) == false);    
    CHECK(canWinNim(11) == false);  
    CHECK(canWinNim(12) == false);  
    CHECK(canWinNim(19) == true);  
    CHECK(canWinNim(20) == true);  
    CHECK(canWinNim(21) == true);  
    CHECK(canWinNim(22) == false);  
    CHECK(canWinNim(23) == false);  
    CHECK(canWinNim(24) == false);  
}