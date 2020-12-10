/**
 * DAY-56 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Create a function that takes a strings characters as ASCII and returns each characters hexadecimal value 
 * as a string.
 * 
 * @param text Text input
 * @return Each text input characters hexadecimal value as a string
 */ 
std::string toHex(std::string text) {
    std::string r;
    for (int i = 0; i < text.size(); i++) {
        std::stringstream ssHex;
        ssHex << std::setw(2) << std::setfill('0') << std::hex << (int) text[i];
        r += r.empty() ? ssHex.str() : " " + ssHex.str();
        
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(toHex("hello world") == "68 65 6c 6c 6f 20 77 6f 72 6c 64");
    CHECK(toHex("Big Boi") == "42 69 67 20 42 6f 69");
    CHECK(toHex("Marty Poppinson") == "4d 61 72 74 79 20 50 6f 70 70 69 6e 73 6f 6e");
}

