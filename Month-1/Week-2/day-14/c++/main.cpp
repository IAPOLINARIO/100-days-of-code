/**
 * DAY-14 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  Encrypts input.
 *  @param s lowercase string 
 *  @return encrypted string
 */
std::string encrypt(std::string s)
{    
    std::reverse(s.begin(), s.end());
    std::replace(s.begin(), s.end(), 'a', '0');
    std::replace(s.begin(), s.end(), 'e', '1');
    std::replace(s.begin(), s.end(), 'i', '2');
    std::replace(s.begin(), s.end(), 'o', '2');
    std::replace(s.begin(), s.end(), 'u', '3');
    return s + "aca";
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(encrypt("banana") == "0n0n0baca");      
    CHECK(encrypt("karaca") == "0c0r0kaca");      
    CHECK(encrypt("burak") == "k0r3baca");      
    CHECK(encrypt("alpaca") == "0c0pl0aca");      
}