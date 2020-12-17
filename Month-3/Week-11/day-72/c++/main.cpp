/**
 * DAY-72 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Tranlator to L33T.
 * @param w Word
 * @return Translated word
 */ 
std::string translateToL33T(std::string w) {    
    std::map<char, std::string> l33t;
    l33t['A'] = "4";
    l33t['B'] = "6";
    l33t['E'] = "3";
    l33t['I'] = "1";
    l33t['M'] = "(V)";
    l33t['N'] = "(\\)";
    l33t['O'] = "0";
    l33t['S'] = "5";
    l33t['T'] = "7";
    l33t['V'] = "\\/";
    l33t['W'] = "`//";

    std::string r;
    for (size_t i = 0; i < w.size(); i++) {
        char c = toupper(w[i]);
        if (l33t.find(c) != l33t.end()) {
            r += l33t[c];
        } else {
            r += c;
        }

    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(translateToL33T("storm") == "570R(V)");
}


