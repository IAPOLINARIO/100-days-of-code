/**
 * DAY-06 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Check if number is prime
 *
 * @param number 
 * @return true/false for prime
 */
bool isPrime(long int n) {  
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n / 2; i++) {
        if ( n % i == 0)  {
            return false;
        }
    }
    return true;
}

/**
 * Calculate next prime number
 *
 * @param number 
 * @return next prime number
 */
long int nextPrime(long int n) {    
    while (!isPrime(n)) n++;
    return n;
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(nextPrime(12) == 13);
    CHECK(nextPrime(24) == 29);
    CHECK(nextPrime(11) == 11);
    CHECK(nextPrime(992) == 997);
    CHECK(nextPrime(0) == 2);
    CHECK(nextPrime(3) == 3);
    CHECK(nextPrime(-99) == 2);
    CHECK(nextPrime(8979848) == 8979857);
    CHECK(nextPrime(999999999) == 1000000007);
}