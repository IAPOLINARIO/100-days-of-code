/**
 * DAY-82 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Get the Last Tidy Number from 1 to n
 * @param n The last number from 1 to n
 * @return The Last Tidy Number
 */ 
unsigned long long lastTidy(unsigned long long n) {    
    std::string ns = std::to_string(n);    
    const size_t nz = ns.size();
    char c = '0';
    bool isTidy = true;
    for (size_t i = 0; i < nz; i++) {
        if (ns[i] >= c) {
            c = ns[i];
        } else {                    
            //after detecting the decreasing digit, get the number from index 0 to current index, and subtract 1.
            //after that, complete with '9's (e.g.: 2020 -> 1999)    
            ns = std::to_string(atol(ns.substr(0, i).c_str()) - 1) + std::string(nz - i, '9');
            isTidy = false;
            break;
        }
    }

    const unsigned long long r = atol(ns.c_str());

    if (isTidy) {
        return r;
    } else {
        return lastTidy(r); //check again the new number, needed for cases like '111111111111111110' in the tests below
    }    
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(lastTidy(2020) == 1999);
    CHECK(lastTidy(3914589564) == 3899999999);
    CHECK(lastTidy(132) == 129);
    CHECK(lastTidy(1000) == 999);
    CHECK(lastTidy(7) == 7);
    CHECK(lastTidy(111111111111111110) == 99999999999999999);    
}