/**
 * DAY-24 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 * This classic problem dates back to Roman times. 
 * There are 41 soldiers arranged in a circle. 
 * Every third soldier is to be killed by their captors, continuing around the circle until only one soldier remains. 
 * He is to be freed. 
 * ssuming you would like to stay alive, at what position in the circle would you stand?
 *
 * Generalize this problem by creating a function that accepts the number of soldiers n 
 * and the interval at which they are killed k, and returns the position of the fortunate survivor.
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * A soldier
 */
struct Soldier {
    int position = 0; 
    bool alive = true;
    Soldier *next = nullptr;

    /**
     * Constructor of each Soldier.
     * @param pos the position of the new soldier in the circle     
     */    
    Soldier(int pos) {
        this->position = pos;        
    }    

    /**
     * The act of killing the next soldier, respecting the interval.
     * @param k the interval of soldiers to kill
     * @return the next alive soldier
     */
    Soldier* kill(int k) {        
        int count = 1;
        Soldier *soldierToKill = this;
        while (count < k) {
            soldierToKill = soldierToKill->next;            
            count = (soldierToKill->alive) ? count + 1 : count;
        }        
        soldierToKill->alive = false;
        
        Soldier *nextAlive = soldierToKill->next;
        while (!nextAlive->alive) {
            nextAlive = nextAlive->next;
        }

        return nextAlive;
    }
};

/**
 * The Josephus Problem
 * @param n number of soldiers
 * @param k the interval at which they are killed
 * @return the position of the fortunate survivor
 */ 
int josephus(int n, int k) {
    int survivorPosition;

    //create the soldiers, arranged in circle
    Soldier *firstSoldier = new Soldier(1);
    Soldier *soldier = firstSoldier;
    for (int i = 2; i <= n; i++) {
        soldier->next = new Soldier(i);
        soldier = soldier->next;                       
    }
    soldier->next = firstSoldier;


    //start the killing!
    soldier = firstSoldier;
    int kills = 0;
    while (++kills <= n - 1) { //the final number of kills will always be n - 1
        soldier = soldier->kill(k);
    }

    //get the survivor's position
    survivorPosition = soldier->position;

    //clean up the circle
    soldier = firstSoldier;    
    do  {
        Soldier *toDelete = soldier;        
        soldier = soldier->next;
        delete toDelete;
    } while (soldier != firstSoldier);    
    
    //return the survivor's position
    return survivorPosition;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{           
    CHECK(josephus(41, 3) == 31);
    CHECK(josephus(35, 11) == 18);
    CHECK(josephus(2, 2) == 1);
    CHECK(josephus(11, 1) == 11);
    CHECK(josephus(5, 2) == 3);
}