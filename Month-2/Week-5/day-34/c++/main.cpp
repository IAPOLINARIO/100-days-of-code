/**
 * DAY-34 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Count the number of carry operations of a sum of two unsigned integers.
 * Each number is less than 10 digits.
 * @param num1 The first number to sum
 * @param num2 The second number to sum
 * @return Number of carry operations of a sum of two unsigned integers less than 10 digits each
 */ 
int carryOperations(int num1, int num2) {    
    const int CARRY_LIMIT = 10; 
    const int SIZE_LIMIT = 9;

    std::string snum1 = std::to_string(num1);
    std::string snum2 = std::to_string(num2);

    //check constraints of challenge
    if (num1 < 0 || num2 < 0 || snum1.size() > SIZE_LIMIT || snum2.size() > SIZE_LIMIT) {        
        return -1;
    }    

    snum1.insert(snum1.begin(), SIZE_LIMIT - snum1.length(), '0');
    snum2.insert(snum2.begin(), SIZE_LIMIT - snum2.length(), '0');

    int count = 0;
    int pastCarry = 0;
    for (int i = snum1.size() - 1; i >= 0; i--) {  
        int sum = (snum1[i] - '0') + (snum2[i] - '0') + pastCarry;
        bool currentCarry = sum >= CARRY_LIMIT;
        count += currentCarry ? 1 : 0; 
        pastCarry = currentCarry ? 1 : 0; 
    }

    return count;
}


/**
 * Tests
 */
TEST_CASE("Tests")
{           
    CHECK(carryOperations(123, 456) == 0);
    CHECK(carryOperations(123, 594) == 1);
    CHECK(carryOperations(555, 555) == 3);
    CHECK(carryOperations(555, 545) == 3);
    CHECK(carryOperations(1, 20000) == 0);
    CHECK(carryOperations(1, 2) == 0);
    CHECK(carryOperations(9999999, -2) == -1);
    CHECK(carryOperations(1234567890, 1) == -1);
}