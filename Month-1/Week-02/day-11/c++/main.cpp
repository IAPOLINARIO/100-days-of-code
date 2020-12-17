/**
 * DAY-11 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Validation of IP part 
 */
bool isValid(std::string ipPart) {
    return !(stoi(ipPart) > 255 ) && !(ipPart.size() > 1 && ipPart[0] == '0');
}

/**
 * Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.
 * @param s digits
 * @return all possible valid IP addresses
 */
std::vector<std::string> restoreIPs(std::string s)
{
    std::vector<std::string> r;        
    if (s.size() >= 4 && s.size() <= 12)
    {                    
        for (int w = 1; w <= 3; w++) {
            for (int x = 1; x <= 3; x++) {
                for (int y = 1; y <= 3; y++) {
                    for (int z = 1; z <= 3; z++)
                    {
                        if (!(w + x + y + z > s.length() || w + x + y + z < s.length())) {
                            std::string part1 = s.substr(0, w);
                            std::string part2 = s.substr(w, x);
                            std::string part3 = s.substr(w + x, y);
                            std::string part4 = s.substr(w + x + y, z);

                            if (isValid(part1) && isValid(part2) && isValid(part3) && isValid(part4)) {                                
                                r.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                            }                        
                        }                    
                    }
                }
            }
        }
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(restoreIPs("0.011.255.245") == std::vector<std::string>{});
    CHECK(restoreIPs("0000") == std::vector<std::string>{"0.0.0.0"});
    CHECK(restoreIPs("1111") == std::vector<std::string>{"1.1.1.1"});    
    CHECK(restoreIPs("010010") == std::vector<std::string>{"0.10.0.10", "0.100.1.0"});
    CHECK(restoreIPs("101023") == std::vector<std::string>{"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"});    
}