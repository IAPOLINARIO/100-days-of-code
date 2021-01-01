/**
 * DAY-94 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Superhero Transformation
 * @param Hero s
 * @param Hero t
 * @return True if the transformation is possible
 */ 
bool superHeroTransform(std::string s, std::string t) {
    if (s.size() != t.size()) {
        return false;
    }
    
    const std::map<char, bool> v = {{'a', true},{'e', true},{'i', true},{'o', true},{'u', true}};
    
    bool r = true;
    for (size_t i = 0; i < s.size(); i++) {
       if ((v.find(s[i]) != v.end() && v.find(t[i]) == v.end()) || (v.find(s[i]) == v.end() && v.find(t[i]) != v.end())) {
           return false;
       }
    }

    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(superHeroTransform("a", "u"));
    CHECK(superHeroTransform("abc", "ukm"));
    CHECK(superHeroTransform("akm", "ua") == false);
    CHECK(superHeroTransform("akm", "uam") == false);
}











