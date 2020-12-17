/**
 * DAY-71 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

bool updt1(std::vector<int> &curr, std::vector<int> &next) {
    bool r = false;
    if (next[0] >= curr[0] && next[1] >= curr[1]) {
        next[0] = curr[0];
        r = true;
    } 
    return r;
}

bool updt2(std::vector<int> &curr, std::vector<int> &next) {
    bool r = false;
    if (next[1] <= curr[1] && next[1] >= curr[0]) {
        next[1] = curr[1];
        r = true;
    }   
    return r;
}

bool checks(std::vector<int> &curr, std::vector<int> &next) {
    bool r0 = false;
    if ((next[0] >= curr[0] && next[1] <= curr[1]) || (next[0] <= curr[0] && next[1] >= curr[0])) {            
       updt1(curr, next);
       updt2(curr, next);
       r0 = true;        
    }
    bool r1 = updt1(curr, next);
    bool r2 = updt2(curr, next);    
    return r0 || r1 || r2;    
}

/**
 * How long has the light been on?
 * @param visits Time points for each person that entered and exited the room
 * @return Hours the light was on
 */ 
int lightOn(std::vector<std::vector<int>> visits) {        
    for (int i = visits.size() - 1; i > 0; i--) {        
        std::vector<int> next = visits[i - 1];
        if (checks(visits[i], next)) {
            visits[i - 1] = next;
            visits.erase(visits.begin() + i);
        }
    }    
    int r = 0;
    for (auto &v : visits) {
        r += v[1] - v[0];
    }
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(lightOn({{1,3},{2,3},{4,5}}) == 3);    
    CHECK(lightOn({{2,4},{3,6},{1,3},{6,8}}) == 7);
    CHECK(lightOn({{6,8},{5,8},{8,9},{5,7},{4,7}}) == 5);
}


