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
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * @param p Digits 
 * @return string with all letter combinations
 */
std::vector<std::string> letterCombinations(std::string p) {
    p.erase(std::remove_if(p.begin(), p.end(), checkInvalidOption), p.end()); //sanitize phone input, removing all non valid characters    
    std::vector<std::string> r{""};

    for (int x = 0; x < p.size(); x++) {        
        std::string charsFromDigit = getCharsFromDigit(p[x]);

        std::vector<std::string> rAux;
        for (int y = 0; y < charsFromDigit.size(); y++) {            
            for (int z = 0; z < r.size(); z++) {                                
                rAux.push_back(r[z] + charsFromDigit[y]);
            }                      
        }        
        r = rAux;   
    }

    std::sort(r.begin(), r.end()); 
    if (r[0] == "") {
        r.clear();
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
    CHECK(letterCombinations("21") == std::vector<std::string>{"a", "b", "c"});    
    CHECK(letterCombinations("23") == std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});            
    CHECK(letterCombinations("2-3") == std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});            
    CHECK(letterCombinations("92") == std::vector<std::string>{"wa", "wb", "wc", "xa", "xb", "xc", "ya", "yb", "yc", "za", "zb", "zc"});  
    CHECK(letterCombinations("456") == std::vector<std::string>{"gjm", "gjn", "gjo", "gkm", "gkn", "gko", "glm", "gln", "glo", "hjm", "hjn", "hjo", "hkm", "hkn", "hko", "hlm", "hln", "hlo", "ijm", "ijn", "ijo", "ikm", "ikn", "iko", "ilm", "iln", "ilo"});  
}