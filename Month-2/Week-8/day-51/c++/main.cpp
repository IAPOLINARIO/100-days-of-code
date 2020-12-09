/**
 * DAY-51 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <stack>
#include <math.h> //for signbit

/**
 * You are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
 * Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions. 
 * If two asteroids meet, the smaller one will explode. 
 * If both are the same size, both will explode. 
 * Two asteroids moving in the same direction will never meet.
 * 
 * @param asteroids The asteroids
 * @return The state of the asteroids after all collisions
 */ 
std::vector<int> asteroidCollision(std::vector<int> asteroids) {
    std::vector<int> r;
    std::stack<int> s;
    
    if (asteroids.size() == 0) {
        return r;
    }
    
    s.push(asteroids[0]);
    asteroids.erase(asteroids.begin());
    
    for (auto &a : asteroids) {
        if (a == 0) { //invalid scenario by constraints
            r.clear();
            return r; 
        }
        if (signbit(a) == signbit(s.top())) {
            s.push(a);
        } else {
            bool exploded = false;
            while (!s.empty()) {
                if (abs(a) == abs(s.top()) && signbit(a) && !signbit(s.top())) {
                    s.pop();
                    exploded = true;
                    break;
                } else {
                    if (abs(a) > abs(s.top()) && signbit(a) && !signbit(s.top())) {
                        s.pop();                    
                    } else {
                        if (!signbit(a) && signbit(s.top())) {
                            s.push(a);
                        }
                        break;
                    }
                }
            }
            if (s.empty() && !exploded) {
                s.push(a);
            }
        }            
    }

    while (!s.empty()) {
        r.push_back(s.top());
        s.pop();
    }

    std::reverse(r.begin(), r.end());
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
   CHECK(asteroidCollision({5, 10, -5}) == std::vector<int>{5, 10});   
   CHECK(asteroidCollision({8, -8}) == std::vector<int>{});   
   CHECK(asteroidCollision({10, 2, -5}) == std::vector<int>{10});   
   CHECK(asteroidCollision({-2,-1,1,2}) == std::vector<int>{-2,-1,1,2});   
}