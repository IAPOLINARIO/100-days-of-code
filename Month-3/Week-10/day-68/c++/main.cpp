/**
 * DAY-68 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Discover the typing distance.
 * @param data The input numbers
 * @return The distance in cm
 */ 
std::string typingDistance(std::string data) {
    const double SQRT_2 = sqrt(2);
    std::map<std::pair<char, char>, double> k;    
    const auto s = [&](char c1, char c2, double r) {k[std::make_pair(c1, c2)] = r;};

    s('1', '1', 0);
    s('1', '2', 1);
    s('1', '3', 2);
    s('1', '4', 1);    
    s('1', '5', SQRT_2);    
    s('1', '6', 1 + SQRT_2);
    s('1', '7', 2);
    s('1', '8', 1 + SQRT_2);
    s('1', '9', SQRT_2 + SQRT_2);
    s('1', '0', SQRT_2 + 2);    

    s('2', '1', 1);
    s('2', '2', 0);
    s('2', '3', 1);    
    s('2', '4', SQRT_2);    
    s('2', '5', 1);    
    s('2', '6', SQRT_2);    
    s('2', '7', SQRT_2 + 1);    
    s('2', '8', 2);    
    s('2', '9', SQRT_2 + 1);    
    s('2', '0', 3);
    
    s('3', '1', 2);
    s('3', '2', 1);
    s('3', '3', 0);    
    s('3', '4', 1 + SQRT_2);    
    s('3', '5', SQRT_2);    
    s('3', '6', 1);    
    s('3', '7', SQRT_2 + SQRT_2);    
    s('3', '8', SQRT_2 + 1);    
    s('3', '9', 2);    
    s('3', '0', 2 + SQRT_2);

    s('4', '1', 1);
    s('4', '2', SQRT_2);
    s('4', '3', SQRT_2 + 1);    
    s('4', '4', 0);    
    s('4', '5', 1);    
    s('4', '6', 2);    
    s('4', '7', 1);    
    s('4', '8', SQRT_2);    
    s('4', '9', 1 + SQRT_2);    
    s('4', '0', SQRT_2 + 1);

    s('5', '1', SQRT_2);
    s('5', '2', 1);
    s('5', '3', SQRT_2);    
    s('5', '4', 1);    
    s('5', '5', 0);    
    s('5', '6', 1);    
    s('5', '7', SQRT_2);    
    s('5', '8', 1);    
    s('5', '9', SQRT_2);    
    s('5', '0', 2);

    s('6', '1', 1 + SQRT_2);
    s('6', '2', SQRT_2);
    s('6', '3', 1);    
    s('6', '4', 2);    
    s('6', '5', 1);    
    s('6', '6', 0);    
    s('6', '7', 1 + SQRT_2);    
    s('6', '8', SQRT_2);    
    s('6', '9', 1);    
    s('6', '0', SQRT_2);

    s('7', '1', 2);
    s('7', '2', 1 + SQRT_2);
    s('7', '3', SQRT_2 + SQRT_2);    
    s('7', '4', 1);    
    s('7', '5', SQRT_2);    
    s('7', '6', SQRT_2 + 1);    
    s('7', '7', 0);    
    s('7', '8', 1);    
    s('7', '9', 2);    
    s('7', '0', SQRT_2);

    s('8', '1', 1 + SQRT_2);
    s('8', '2', 2);
    s('8', '3', 1 + SQRT_2);    
    s('8', '4', SQRT_2);    
    s('8', '5', 1);    
    s('8', '6', SQRT_2);    
    s('8', '7', 1);    
    s('8', '8', 0);    
    s('8', '9', 1);    
    s('8', '0', 1);

    s('9', '1', SQRT_2 + SQRT_2);
    s('9', '2', SQRT_2 + 1);
    s('9', '3', 2);    
    s('9', '4', SQRT_2 + 1);    
    s('9', '5', SQRT_2);    
    s('9', '6', 1);    
    s('9', '7', 2);    
    s('9', '8', 1);    
    s('9', '9', 0);    
    s('9', '0', SQRT_2);    

    s('0', '1', SQRT_2 + 2);
    s('0', '2', 3);
    s('0', '3', SQRT_2 + 2);    
    s('0', '4', SQRT_2 + 1);    
    s('0', '5', 2);    
    s('0', '6', SQRT_2 + 1);    
    s('0', '7', SQRT_2);    
    s('0', '8', 1);    
    s('0', '9', SQRT_2);    
    s('0', '0', 0);    

    double r = 0;
    std::string ns;    
    for (size_t i = 0; i < data.size(); i++) {
        if (isdigit(data[i])) {
            ns += data[i];
        }
    }
    for (size_t i = 0; i < ns.size() - 1; i++) {        
        r += k[std::make_pair(ns[i], ns[i + 1])];
    }
    
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << r;
    return ss.str() + " cm";
}

/**
 * Tests
 */
TEST_CASE("Tests")
{  
    CHECK(typingDistance("219.45.143.143)") == "17.49 cm");    
    CHECK(typingDistance("(7851)") == "3.41 cm");
    CHECK(typingDistance("(1111)") == "0.00 cm");        
    CHECK(typingDistance("(123654789)") == "8.00 cm");
    CHECK(typingDistance("-(123654-789") == "8.00 cm");
}