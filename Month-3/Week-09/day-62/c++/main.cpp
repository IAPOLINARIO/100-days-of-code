/**
 * DAY-62 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * How many fruits can harvest this week?
 * @param plantWeek The plants of each week
 * @param week The week
 * @return Number of fruits
 */ 
int harvest(std::vector<int> &plantWeek, int week) {
    int r = 0;
    for (auto &p : plantWeek) {
        r += week - p;
    }
    return r;
}

/**
 * Funny plant
 * @param people Number of people
 * @param fruits Number of starting fruits
 * @return Number of weeks you can support a group of x people, given y fruits to start with
 */ 
int funnyPlant(int people, int fruits) {    
    if (fruits >= people) {
        return 0;
    }    
    int week = 1;
    std::vector<int> plantWeek;    

    while (fruits < people) {                
        //if there is some fruits avaialable, plant them except if ammount is already enough for the people next week        
        if ((harvest(plantWeek, week + 1) + fruits) < people && fruits > 0) { 
            fruits--; //consume a fruit to plant
            plantWeek.push_back(week); //plant in this week
            continue;
        }
        
        week++; //1 week later
        fruits += harvest(plantWeek, week); //harvest from plants
    }
    
    return week;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(funnyPlant(21, 1) == 5);
    CHECK(funnyPlant(200, 15) == 5);
    CHECK(funnyPlant(50000, 1) == 14);
    CHECK(funnyPlant(150000, 250) == 9);
}

