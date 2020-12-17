/**
 * DAY-30 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Get the maximum possible value obtained by inserting one single digit inside the decimal 
 * representation of integer N
 * @param n The decimal representation of integer
 * @param digit The single digit to be inserted
 * @return the maximum value
 */  
int maximumValueAfterDigitInsert(int n, char digit) {
    if (!isdigit(digit)) { //check invalid digit
        return n;
    }    
    
    std::string ns = std::to_string(n);

    if (n < 0) {
        n = (digit < ns[1]) ? (std::stoi(ns[0] + std::to_string(digit - '0') + ns.substr(1, std::string::npos))) : std::stoi(ns.substr(0) + digit);
        return n;
    }

    for (int i = 0; i < ns.size(); i++) {
        if (digit > ns[i]) {
            return std::stoi(ns.substr(0, i) + digit + ns.substr(i));            
        }
    }
    
    return std::stoi(ns + digit);
}

/**
 * Tests
 */
TEST_CASE("Tests")
{           
    CHECK(maximumValueAfterDigitInsert(1, '!') == 1);
    CHECK(maximumValueAfterDigitInsert(0, '3') == 30);
    CHECK(maximumValueAfterDigitInsert(2, '5') == 52);
    CHECK(maximumValueAfterDigitInsert(5, '2') == 52);
    CHECK(maximumValueAfterDigitInsert(276, '3') == 3276);
    CHECK(maximumValueAfterDigitInsert(860, '7') == 8760);
    CHECK(maximumValueAfterDigitInsert(-10, '2') == -102);
    CHECK(maximumValueAfterDigitInsert(-999, '4') == -4999);    
}