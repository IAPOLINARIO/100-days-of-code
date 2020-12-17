/**
 * DAY-66 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <random>

/**
 * ISBN Validator
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
 * ISBN Generator
 * @return ISBN code
 */ 
std::string ISBNGenerator(void) {
    std::random_device rd; // only used once to initialise (seed) engine
    std::mt19937 rng(rd());// random-number engine used (Mersenne-Twister in this case)  
    std::uniform_int_distribution<int> uni(0, 9); // guaranteed unbiased
    
    while (true) {
        std::string buildingCode;    
        std::string finalCode;    
        for (size_t i = 0; i < 9; i++) {            
            buildingCode += std::to_string(uni(rng));
        }
        for (size_t i = 0; i <= 10; i++) {            
            if (i == 10) {
                finalCode = buildingCode + 'X';
            } else {
                finalCode = buildingCode + std::to_string(i);
            }            
            if (ISBNvalidator(finalCode)) {                
                return finalCode;
            }
        }        
    }
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    std::cout << "\n\nGenerating ONE MILLION ISBN codes...\n" << std::endl;    
    const int MAX_ISBN = 1000000;
    for (size_t i = 0; i < MAX_ISBN; i++) {
        CHECK(ISBNvalidator(ISBNGenerator()));
    }    
}

