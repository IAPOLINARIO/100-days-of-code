/**
 * DAY-07 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <list>

/**
 * Merge two lists of numbers.
 *
 * @param num1 integers
 * @param num2 integers
 * @return ordered list
 */
std::list<int> merge(std::list<int> nums1, std::list<int> nums2) {    
    nums1.sort();
    nums2.sort();
    nums1.merge(nums2);
    return nums1;
}

/**
 * Tests
 */
TEST_CASE("Tests") {    
    CHECK(merge({1, 2, 3}, {4, 5, 6}) == std::list<int> {1, 2, 3, 4, 5, 6});
    CHECK(merge({6, 5, 4}, {3, 2, 1}) == std::list<int> {1, 2, 3, 4, 5, 6});
    CHECK(merge({0, 0, 0}, {0, 0, 1}) == std::list<int> {0, 0, 0, 0, 0, 1});
    CHECK(merge({1, 2, 3}, {}) == std::list<int> {1, 2, 3});
    CHECK(merge({1, 2, -3}, {-9, 99, -100000}) == std::list<int> {-100000, -9, -3, 1, 2, 99});    
}