/**
 * DAY-03 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <vector>

/**
 * Calculate skewers of the barbecue.
 *
 * @param vector of strings representing the barbecue
 * @return vector of ints representing [# vegetarian skewers, # non-vegetarian skewers]
 */
std::vector<int> bbqSkewers(std::vector<std::string> &bbq) {
    int veg = 0;
    int meat = 0;    
    
    for (auto e: bbq) {
        e.find("x") != std::string::npos ? meat++ : e.find("o") != std::string::npos ? veg++ : 0;        
    }
    
    return std::vector<int> {veg, meat};
}

/**
 * BBBQ SKEWERS TEST
 */
TEST_CASE("BBBQ SKEWERS TEST") {    
    //[2 vegetarian skewers, 3 non-vegetarian skewers]
    std::vector<std::string> input = {
        "--oooo-ooo--", 
        "--xx--x--xx--",
        "--o---o--oo--",
        "--xx--x--ox--",
        "--xx--x--ox--"
    };    
    CHECK(bbqSkewers(input) == std::vector<int> {2, 3});

    //[3 vegetarian skewers, 2 non-vegetarian skewers]
    input = {
        "--oooo-ooo--",
        "--xxxxxxxx--",
        "--o---",
        "-o-----o---x--",
        "--o---o-----"
    };
    CHECK(bbqSkewers(input) == std::vector<int> {3, 2});


    //[1 vegetarian skewers, 4 non-vegetarian skewers]
    input = {
        "--xxxx-ooo--", 
        "--xx--x--xx--",
        "--o---o--oo--",
        "--xx--x--ox--",
        "--xx--x--ox--"
    };    
    CHECK(bbqSkewers(input) == std::vector<int> {1, 4});

    //[2 vegetarian skewers, 9 non-vegetarian skewers]
    input = {
        "--xxxx-ooo--", 
        "--o--x--xx--",
        "--o---o--oo--",
        "--xx--x--ox--",
        "------x--ox--",
        "--xx--x--ox--",
        "--xx--x--ox--",
        "---o-oo--ox--",
        "--xx--x--ox--",
        "--xx--x--oo--",
        "--------o----"
    };    
    CHECK(bbqSkewers(input) == std::vector<int> {2, 9});

    //[0 vegetarian skewers, 0 non-vegetarian skewers]
    input = {};
    CHECK(bbqSkewers(input) == std::vector<int> {0, 0});

    //[0 vegetarian skewers, 0 non-vegetarian skewers]
    input = {
        "test1", 
        "test2"
    };
    CHECK(bbqSkewers(input) == std::vector<int> {0, 0});
}