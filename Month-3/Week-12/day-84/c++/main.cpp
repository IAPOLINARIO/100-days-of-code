/**
 * DAY-84 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Vestigium
 * 
 * @param m Square matrix of integer values
 * @return std::array<int, 3> of: TRACE, REPEATED ROWS, REPEATED COLUMNS
 */ 
std::array<int, 3> vestigium(std::vector<std::vector<int>> m) {
    //lambda to get the repetition count of row or colum
    auto repeat = [&](const int &v, std::vector<int> &l) {  
        auto it = std::find(l.begin(), l.end(), v);
        if (it != l.end()) {
            return true;           
        } 
        l.push_back(v);
        return false;
    };
    
    std::array<int, 3> r = {0, 0, 0}; //trace, repeated rows, repeated columns
    for (int j = 0; j < m.size(); j++) {
        std::vector<int> rc;
        std::vector<int> rr;

        r[0] += m[j][j]; //calc strace                             
                
        bool brcol = false;
        bool brrow = false;
        for (int i = 0; i < m.size(); i++) {
            if (!brcol) {
                brcol = repeat(m[i][j], rc);                
            }
            if (!brrow) {
                brrow = repeat(m[j][i], rr);              
            }
        }        
        r[1] += brrow ? 1 : 0; //repeated rows     
        r[2] += brcol ? 1 : 0; //repeated columns
    }    
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(vestigium({{1,2,3,4},
                     {2,1,4,3},
                     {3,4,1,2},
                     {4,3,2,1}}) == std::array<int, 3>{4, 0, 0});

    CHECK(vestigium({{2,2,2,2},
                     {2,3,2,3},
                     {2,2,2,3},
                     {2,2,2,2}}) == std::array<int, 3>{9, 4, 4});

    CHECK(vestigium({{2,1,3},
                     {1,3,2},
                     {1,2,3}}) == std::array<int, 3>{8, 0, 2});                     
}