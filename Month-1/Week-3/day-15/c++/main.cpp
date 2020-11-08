/**
 * DAY-15 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Sum all the ASCII code from input.
 * @param word
 * @return sum of all ASCII code from input
 */
int count(std::string &w) {
    int r = 0;
    for (auto &c : w) {
        r += c;
    }
    return r;
}

/**
 *  Given two strings s and t , write a function to determine if t is an anagram of s.
 *  @param s string1
 *  @param t string1
 *  @return true if t is an anagram of s
 */
bool isAnagram(std::string s, std::string t)
{    
    return count(s) == count(t);
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(isAnagram("anagram", "nagaram") == true);
    CHECK(isAnagram("muro", "rumo") == true);
    CHECK(isAnagram("carro", "corar") == true);
    CHECK(isAnagram("alegria", "alergia") == true);
    CHECK(isAnagram("alegria", "regalia") == true);
    CHECK(isAnagram("alegria", "galeria") == true);
    CHECK(isAnagram("cantiga", "catinga") == true);

    CHECK(isAnagram("rat", "car") == false);
    CHECK(isAnagram("teste", "este") == false);
    CHECK(isAnagram("a", "b") == false);
}