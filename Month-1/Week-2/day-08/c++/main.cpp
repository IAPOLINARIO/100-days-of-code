/**
 * DAY-08 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

//helper function to sanitize invalid inputs
bool checkInvalidOption(int c) { return !isdigit(c) || c == '0' || c == '1'; }

/**
 * Get chars from a digit
 * @param d Digit 
 * @return string with all chars combinations
 */
std::string getCharsFromDigit(char d) {
    std::string r;    
    for (int i = 0; i < ((d == '7' || d == '9') ? 4 : 3); i++) {
        r += (d + 47 + (2 * ((d - '0') - 2)) + i + (d > '7' ? 1 : 0)); 
    }
    return r;
}

/**
 * Get all the letter combinations from a phone number.
 *
 * @param Phone Number
 * @return Vector with all possible letter combinations that the number could represent, ordered
 */
std::vector<std::string> letterCombinations(std::string p) {            
    p.erase(std::remove_if(p.begin(), p.end(), checkInvalidOption), p.end()); //sanitize phone input, removing all non valid characters
    
    std::vector<std::string> r;
    for (int w = 0; w < p.size(); w++) {            
        std::string charsFromDigitStart = getCharsFromDigit(p[w]);        
        for (int x = 0; x < charsFromDigitStart.size(); x++) {
            if (p.size() == 1) {
                r.push_back({charsFromDigitStart[x]});
                continue;
            }
            for (int y = w + 1; y < p.size(); y++) {    
                std::string charsFromDigitNext = getCharsFromDigit(p[y]);                
                for (int z = 0; z < charsFromDigitNext.size(); z++) {                    
                    r.push_back({charsFromDigitStart[x], charsFromDigitNext[z]});
                }                
            }            
        }        
    }     
    return r;   
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(letterCombinations("") == std::vector<std::string>{});    
    CHECK(letterCombinations("1*A----01Z") == std::vector<std::string>{});    
    CHECK(letterCombinations("1*A----01Z2") == std::vector<std::string>{"a", "b", "c"}); 
    CHECK(letterCombinations("2") == std::vector<std::string>{"a", "b", "c"});        
    CHECK(letterCombinations("23") == std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});            
    CHECK(letterCombinations("21") == std::vector<std::string>{"a", "b", "c"});    
    CHECK(letterCombinations("2-3") == std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});            
    CHECK(letterCombinations("234") == std::vector<std::string>{"ad", "ae", "af", "ag", "ah", "ai", "bd", "be", "bf", "bg", "bh", "bi", "cd", "ce", "cf", "cg", "ch", "ci", "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi"});
    CHECK(letterCombinations("9") == std::vector<std::string>{"w", "x", "y", "z"});        
    CHECK(letterCombinations("92") == std::vector<std::string>{"wa", "wb", "wc", "xa", "xb", "xc", "ya", "yb", "yc", "za", "zb", "zc"});
}