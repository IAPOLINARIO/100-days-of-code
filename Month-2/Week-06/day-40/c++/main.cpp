/**
 * DAY-40 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Check if is possible to sort array using the following operation any number of times: 
 * Choose any 3 consecutive indices and rotate their elements in such a way that ABC ➞ BCA ➞ CAB ➞ ABC.
 * 
 * @param a Sequence of natural numbers incrementing from 1
 * @param true if it is possible
 */ 
bool larryArray(std::vector<int> a) {
    int inversions = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            inversions += a[i] > a[j] ? 1 : 0;
        }
    }
    return inversions % 2 == 0;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(larryArray({1, 6, 5, 2, 4, 3}) == true);
    CHECK(larryArray({3, 2, 1, 5, 6}) == false);
    CHECK(larryArray({1, 2, 3, 5, 4}) == false);        
    CHECK(larryArray({3, 1, 2}) == true);
    CHECK(larryArray({1, 3, 4, 2}) == true);

}