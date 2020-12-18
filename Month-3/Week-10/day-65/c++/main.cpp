/**
 * DAY-65 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * ISBN Validaor
 * @param code Book code
 * @return true if ISBN is OK
 */ 
bool ISBNvalidator(std::string code) {    
    int count = 0;
    int countDown = 10;
    int sum = 0;    
    for (size_t i = 0; i < code.size(); i++) {
        if ((!isdigit(code[i]) && code[i] != 'X' && code[i] != '-') || 
            (code[i] == '-' && ((i == 0 || i == code.size() - 1) || (i > 0 && i < code.size() - 1 && (code[i - 1] == '-' || code[i + 1] == '-'))))) {
            return false; //invalid input
        }        
        if (code[i] != '-') {
            count++;
            if (code[i] == 'X') {
                sum += countDown * 10;
            } else {
                sum += countDown * (code[i] - '0'); //convert char to int
            }            
            countDown--;
        }
    }
    if (count != 10) {
        return false;
    }
    return sum % 11 == 0;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(ISBNvalidator("0-7475-3269-9") == true);    
    CHECK(ISBNvalidator("156881111X") == true);
    CHECK(ISBNvalidator("0-7475-3269-91") == false);    
    CHECK(ISBNvalidator("--7475-3269-9") == false);    
}

