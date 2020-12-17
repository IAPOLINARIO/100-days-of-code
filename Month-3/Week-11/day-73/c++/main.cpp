/**
 * DAY-73 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * L33T -> 'English'
 * @param w Word
 * @return Translated word
 */ 
std::string L33TtoEnglish(std::string w) {    
    std::map<std::string, char> em;
    em["4"] = 'A';
    em["6"] = 'B';
    em["3"] = 'E';
    em["1"] = 'I';
    em["(V)"] = 'M';
    em["(\\)"] = 'N';
    em["0"] = 'O';
    em["5"] = 'S';
    em["7"] = 'T';
    em["\\/"] = 'V';
    em["`//"] = 'W';

    std::string r;
    const int SIZE = w.size();
    for (size_t i = 0; i < SIZE; i++) {                        
        std::string s(1, w[i]);        
        bool found = em.find(s) != em.end();
        if (!found) {            
            if ((i + 1) < SIZE) {                
                s += w[i + 1];
                found = em.find(s) != em.end();
                 i += found ? 1 : 0;
                if (!found) {
                    if ((i + 2) < SIZE) {
                        s += w[i + 2];
                        found = em.find(s) != em.end();
                        i += found ? 2 : 0;
                    } 
                } 
            }                    
        }
        if (found) {
            r += em[s];
        } else {
            r += w[i];
        }

    }

    std::transform(r.begin(), r.end(), r.begin(), [](unsigned char c){ return std::tolower(c); }); //lowercase based on challenge example
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(L33TtoEnglish("570R(V)") == "storm");
}


