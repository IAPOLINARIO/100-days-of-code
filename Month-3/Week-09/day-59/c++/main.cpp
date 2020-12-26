/**
 * DAY-59 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <algorithm>

/**
 * Perfectly balanced
 * Given a string containing only lowercase letters, find whether every letter that appears in the string appears the same number of times. Don't forget to handle the empty string ("") correctly!
 * 
 * @param w content
 * @return true if Perfectly balanced
 */ 
bool balanced_bonus(std::string w) {
    if (w.size() == 0) {
        return true;
    }

    std::map<char, int> wm;
    for (int i = 0; i < w.size(); i++) {
        wm[w[i]] += 1;
    }
    
    for (auto &e : wm) {
        if (e.second != wm[w[0]]) {
            return false;
        }
    }

    return true;
}

/**
 * Perfectly balanced (second version)
 * Given a string containing only lowercase letters, find whether every letter that appears in the string appears the same number of times. Don't forget to handle the empty string ("") correctly!
 * 
 * @param w content
 * @return true if Perfectly balanced
 */ 
bool balanced_bonus_second_version(const std::string w) {    
    for (size_t i = 1; i < w.size(); i++) {
        if (std::count(w.begin(), w.end(), w[i]) != std::count(w.begin(), w.end(), w[0])) {
            return false;
        }
    }
    return true;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(balanced_bonus("xxxyyyzzz") == true);
    CHECK(balanced_bonus("abccbaabccba") == true);
    CHECK(balanced_bonus("xxxyyyzzzz") == false);
    CHECK(balanced_bonus("abcdefghijklmnopqrstuvwxyz") == true);
    CHECK(balanced_bonus("pqq") == false);
    CHECK(balanced_bonus("fdedfdeffeddefeeeefddf") == false);
    CHECK(balanced_bonus("www") == true);
    CHECK(balanced_bonus("x") == true);
    CHECK(balanced_bonus("") == true);    

    CHECK(balanced_bonus_second_version("xxxyyyzzz") == true);
    CHECK(balanced_bonus_second_version("abccbaabccba") == true);
    CHECK(balanced_bonus_second_version("xxxyyyzzzz") == false);
    CHECK(balanced_bonus_second_version("abcdefghijklmnopqrstuvwxyz") == true);
    CHECK(balanced_bonus_second_version("pqq") == false);
    CHECK(balanced_bonus_second_version("fdedfdeffeddefeeeefddf") == false);
    CHECK(balanced_bonus_second_version("www") == true);
    CHECK(balanced_bonus_second_version("x") == true);
    CHECK(balanced_bonus_second_version("") == true);    
}





