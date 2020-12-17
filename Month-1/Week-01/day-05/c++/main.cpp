/**
 * DAY-05 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Calculate total of sock pairs
 *
 * @param sequence - Unordered sequence of socks
 * @return total number of sock pairs
 */
int sockPairs(std::string sequence) {
    int pairs = 0;        
    while (sequence.size() > 0) {    
        char sock = sequence[0];
        pairs += std::count(sequence.begin(), sequence.end(), sock) / 2;
        sequence.erase(std::remove(sequence.begin(), sequence.end(), sock), sequence.end());
    }
    return pairs;
}

/**
 * Tests
 */
TEST_CASE("Tests") {        
    CHECK(sockPairs("AAAAAAAAAA") == 5);
    CHECK(sockPairs("ABABC") == 2);
    CHECK(sockPairs("CABBACCC") == 4);
    CHECK(sockPairs(" ") == 0);
    CHECK(sockPairs("") == 0);
    CHECK(sockPairs("ABCDEFGHIJKLMNOPQRSTUVXZ") == 0);
    CHECK(sockPairs("001") == 1);
}