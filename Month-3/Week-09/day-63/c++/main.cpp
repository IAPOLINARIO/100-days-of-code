/**
 * DAY-63 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * The rabbit problem. How long it will take for them to outnumber humans (target)?
 * 
 * Every month a fertile female will have 14 offspring (5 males and 9 females).
 * A female rabbit is fertile when it has reached the age of 4 months, they never stop being fertile.
 * Rabbits die at the age of 8 years (96 months).
 * 
 * @param Number of 2-month-old male rabbits to start
 * @param Number of 2-month-old female rabbits to start
 * @return Number of months to hit the target
 */ 
int rabbit(int male, int female, long int target) {           
    const int ERROR_CODE = -1;    
    const int INITIAL_BATCH_AGE = 2; //each starting rabbit is 2-month-old
    const int AGES = 96; //the lifespan of a rabbit (they die at 96 months)
    const int AGE_ALIVE_LIMIT = 95;
    const int AGE_FERTILE_BEGIN = 4; //A female rabbit is fertile when it has reached the age of 4 months, they never stop being fertile.
    const int NEW_MALES_RATE = 5;
    const int NEW_FEMALES_RATE = 9;

    //check invalid input
    if (female < 0 || male < 0) {
        return -1; //invalid input
    }
    
    //without an starting female the population will not grow
    if ((male + female) < target && female == 0 ) {
        return ERROR_CODE;
    }
        
    int month = 0; //starting month count
    long int f[AGES] = {0}; //initialize all positions with zero for females
    long int m[AGES] = {0}; //initialize all positions with zero for males
        
    f[INITIAL_BATCH_AGE] = female; //input some initial 2-month-old female rabbits
    m[INITIAL_BATCH_AGE] = male; ////input some initial 2-month-old female rabbits
    
    while (true) {
        long int aliveRabbits = 0; //count the alive rabbits on this month

        for (int i = AGE_ALIVE_LIMIT; i >= 0 && aliveRabbits < target; i--) {
            
            //Offspring production
            long int newBornFemale = 0;
            long int newBornMale = 0;
            if (i > AGE_FERTILE_BEGIN) { //A fertile female will always produce 14 offspring (5 male, 9 female)
                newBornFemale = f[i] * NEW_FEMALES_RATE; 
                newBornMale = f[i] * NEW_MALES_RATE;
            } 

            aliveRabbits += f[i] + m[i];

            //Age rabbits
            const int nextGen = i + 1;
            f[nextGen] = f[i];
            m[nextGen] = m[i];                    
            f[i] = 0;
            m[i] = 0;

            //the first generation (index 0) will always be the newborns
            f[0] += newBornFemale;
            m[0] += newBornMale;                        
        }
                    
        if (aliveRabbits >= target) { //check if the rabbit population hit the target            
            return month;
        }    
        month++;
    }    
}


/**
 * Tests
 */
TEST_CASE("Tests")
{  
   CHECK(rabbit(2, 4, 6) == 0);
   CHECK(rabbit(2, 4, 1000000000) == 32);
   CHECK(rabbit(2, 4, 15000000000) == 36);
   CHECK(rabbit(5, 0, 6) == -1);
   CHECK(rabbit(-1, 2, 6) == -1);
}

