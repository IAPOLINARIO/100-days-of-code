/**
 * DAY-23 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *
 *  
 * Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.
 * Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
 * Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
 * Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.
 *
 * The philosophers\' ids are numbered from 0 to 4 in a clockwise order. Implement the function void wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork) where:
 *
 *   philosopher is the id of the philosopher who wants to eat.
 *   pickLeftFork and pickRightFork are functions you can call to pick the corresponding forks of that philosopher.
 *   eat is a function you can call to let the philosopher eat once he has picked both forks.
 *   putLeftFork and putRightFork are functions you can call to put down the corresponding forks of that philosopher.
 *   The philosophers are assumed to be thinking as long as they are not asking to eat (the function is not being called with their number).
 *
 * Five threads, each representing a philosopher, will simultaneously use one object of your class to simulate the process. The function may be called for the same philosopher more than once, even before the last call ends.
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <mutex> //for the std::mutex syncronization primitive
#include <condition_variable> //for the std::condition_variable syncronization primitive
#include <functional> //function as arguments
#include <map> //for the std::map
#include <tuple> //for the std::tuple
#include <thread> //for the std::thread

const int NUMBER_OF_PHILOSOPHERS = 5; //number of philosophers

typedef int PHILOSOPHER_ID; //representation of a philosopher's ID type

//represents all possible operations of a philosopher that can be reported on the summary output
enum PHILOSOPHER_SUMMARY_OPERATION {
    PICK = 1,
    PUT = 2,
    EAT = 3
};

//represents all possible fork interactions of a philosopher that can be reported on the summary output
enum PHILOSOPHER_SUMMARY_FORK_INTERACTION {
    BOTH_FORKS = 0, //used when eating
    LEFT_FORK = 1,
    RIGHT_FORK = 2    
};

//states of a philosopher
enum PHILOSOPHER_STATUS {
    EATING,
    THINKING
};

//each philosopher has two neighbors, left and right
enum PHILOSOPHER_NEIGHBOR_DIRECTION {
    LEFT_PHILOSOPHER = -1,
    RIGHT_PHILOSOPHER = 1
};

//Lambda to get the PHILOSOPHER_ID of a neighbor, based on the reference philosopher id and direction
const auto PHILOSOPHER_NEIGHBOR_POSITION = [] (PHILOSOPHER_ID id, PHILOSOPHER_NEIGHBOR_DIRECTION direction) { 
    PHILOSOPHER_ID neighborID =  (id + direction) % NUMBER_OF_PHILOSOPHERS;
    return neighborID >= 0 ? neighborID : neighborID + NUMBER_OF_PHILOSOPHERS; 
};

std::map<PHILOSOPHER_ID, PHILOSOPHER_STATUS> status; //map to hold status of a philosopher
std::map<PHILOSOPHER_ID, int> remainingServings; //map to hold the number of remaining servings for a philosopher
std::vector<std::tuple<PHILOSOPHER_ID, PHILOSOPHER_SUMMARY_FORK_INTERACTION, PHILOSOPHER_SUMMARY_OPERATION>> summary; //hold a summary of all operations

std::mutex mutex; //MUTEX Synchronization primitive
std::condition_variable cv; //CONDITION VARIABLE synchronization primitive

/**
 * Pick up the left fork.
 * @param id of the philosopher
*/
void pickLeftFork(PHILOSOPHER_ID id) {            
    //register the pickup of the left fork
    summary.push_back(std::make_tuple(id, PHILOSOPHER_SUMMARY_FORK_INTERACTION::LEFT_FORK, PHILOSOPHER_SUMMARY_OPERATION::PICK));
}

/**
 * Pick up the right fork.
 * @param id of the philosopher
*/
void pickRightFork(PHILOSOPHER_ID id) {
    //register the pickup of the right fork
    summary.push_back(std::make_tuple(id, PHILOSOPHER_SUMMARY_FORK_INTERACTION::RIGHT_FORK, PHILOSOPHER_SUMMARY_OPERATION::PICK));
}

/**
 * The philosopher eats.
 * @param id of the philosopher
*/
void eat(PHILOSOPHER_ID id) {
    std::unique_lock<std::mutex> lock(mutex);
    //decrement number of servings for the philosopher
    remainingServings[id] -= 1; 
    //register the eat operation of the philosopher
    summary.push_back(std::make_tuple(id, PHILOSOPHER_SUMMARY_FORK_INTERACTION::BOTH_FORKS, PHILOSOPHER_SUMMARY_OPERATION::EAT));    
}

/**
 * Put down left fork.
 * @param id of the philosopher
 */  
void putLeftFork(PHILOSOPHER_ID id) {
    //register the put down operation of the left fork for the philosopher
    summary.push_back(std::make_tuple(id, PHILOSOPHER_SUMMARY_FORK_INTERACTION::LEFT_FORK, PHILOSOPHER_SUMMARY_OPERATION::PUT));
}

/**
 * Put down right fork.
 * @param id of the philosopher
 */  
void putRightFork(PHILOSOPHER_ID id) {
    //register the put down operation of the right fork for the philosopher
    summary.push_back(std::make_tuple(id, PHILOSOPHER_SUMMARY_FORK_INTERACTION::RIGHT_FORK, PHILOSOPHER_SUMMARY_OPERATION::PUT));
}

/**
 * Prepare to pick up the forks.
 * @param id the philosopher's id
 * @param pickLeftFork function to be called when the left fork is picked up
 * @param pickRightFork function to be called when the left fork is picked up
 */ 
void pickupForks(PHILOSOPHER_ID id, std::function<void (PHILOSOPHER_ID)> pickLeftFork, std::function<void (PHILOSOPHER_ID)> pickRightFork) {
    std::unique_lock<std::mutex> lock(mutex);
    
    while (status[PHILOSOPHER_NEIGHBOR_POSITION(id, PHILOSOPHER_NEIGHBOR_DIRECTION::LEFT_PHILOSOPHER)] == PHILOSOPHER_STATUS::EATING 
        || status[PHILOSOPHER_NEIGHBOR_POSITION(id, PHILOSOPHER_NEIGHBOR_DIRECTION::RIGHT_PHILOSOPHER)] == PHILOSOPHER_STATUS::EATING) {
        //the philosopher needs to wait because at least one neighbor is eating!
        cv.wait(lock);
        //the philosopher woke up, go check if the neighbors are not eating, so he can
    }

    //the philosopher's neighbors aren't eating, so try to pickup the forks!    
    pickLeftFork(id);
    pickRightFork(id);

    //with both forks picked up, the philosopher can now eat, change the status
    status[id] = PHILOSOPHER_STATUS::EATING;    
}


/**
 * Prepare to put down the forks.
 * @param id the philosopher's id
 * @param putLeftFork function to be called when the left fork is put down
 * @param putRightFork function to be called when the left fork is put down
 */ 
void putdownForks(PHILOSOPHER_ID id, std::function<void (PHILOSOPHER_ID)> putLeftFork, std::function<void (PHILOSOPHER_ID)> putRightFork) {
    std::unique_lock<std::mutex> lock(mutex);
        
    putLeftFork(id);
    putRightFork(id);

    //after putting down both forks, resume thinking status    
    status[id] = PHILOSOPHER_STATUS::THINKING;
    
    //notify waiters
    cv.notify_all(); 
}

/**
 * The cycle of each philosopher.
 * Every philosopher run this in your own thread.
 * @param id the id of the philosopher who wants to eat
 * @param pickLeftFork function to call to pick the left fork of the philosopher
 * @param pickRightFork function to call to pick the right fork of the philosopher
 * @param eat function to call to let the philosopher eat once he has picked both forks
 * @param putLeftFork function to call to put down the left fork of the philosopher
 * @param putRightFork function to call to put down the right fork of the philosopher
 */ 
void wantsToEat(PHILOSOPHER_ID id, 
                std::function<void (PHILOSOPHER_ID)> pickLeftFork,
                std::function<void (PHILOSOPHER_ID)> pickRightFork,
                std::function<void (PHILOSOPHER_ID)> eat,
                std::function<void (PHILOSOPHER_ID)> putLeftFork,
                std::function<void (PHILOSOPHER_ID)> putRightFork) {    
    
    //while the philosopher has enough servings reserved to eat
    while (remainingServings[id] > 0) {        
        pickupForks(id, pickLeftFork, pickRightFork);        
        eat(id);        
        putdownForks(id, putLeftFork, putRightFork);        
    }        
}

/**
 * Prepare the philosophers to start their cycles, each one in their own threads.
 * @param n number of portions that each philosopher will be entitled
 * @return List of tuples containing the philosopher's ID, which fork and operation
 */ 
std::vector<std::tuple<PHILOSOPHER_ID, PHILOSOPHER_SUMMARY_FORK_INTERACTION, PHILOSOPHER_SUMMARY_OPERATION>>&  philosophersDinnerSummary(int n) {   
   
   //at beginning, all philosophers are thinking!
   for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
       remainingServings[static_cast<PHILOSOPHER_ID> (i)] = n;
       status[static_cast<PHILOSOPHER_ID> (i)] = PHILOSOPHER_STATUS::THINKING;
   }
   
   //create one thread per philosopher
   std::thread threads[NUMBER_OF_PHILOSOPHERS];         
   for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {       
       threads[i] = std::thread(wantsToEat, static_cast<PHILOSOPHER_ID> (i), pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);       
   }
   
   //blocks the current thread until all philosophers finished their own threads
   for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {       
       threads[i].join();
   }
   
   return summary; //get the results
}

/**
 * Tests
 */
TEST_CASE("Tests")
{           
    const int NUMBER_OF_SERVINGS_PER_PHILOSOPHER = 20;         

    //the 'bill' of a philosopher is the number of servings consumed
    std::map<PHILOSOPHER_ID, int> billOfPhilosopher;    
    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        billOfPhilosopher[static_cast<PHILOSOPHER_ID>(i)] = 0; //start from 0
    }
    
    //start the philosophers cycle and get all the results
    auto r = philosophersDinnerSummary(NUMBER_OF_SERVINGS_PER_PHILOSOPHER);

    //calculate the number of times each philosopher ate
    for (int i = 0; i < r.size(); i++) {
        PHILOSOPHER_SUMMARY_OPERATION op = std::get<2>(r[i]);
        if (op == PHILOSOPHER_SUMMARY_OPERATION::EAT) {
            PHILOSOPHER_ID id = std::get<0>(r[i]);
            billOfPhilosopher[id] += 1;
        }        
    }

    //check if each philosopher ate the predefined number of servings and if their final status is THINKING
    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        CHECK(billOfPhilosopher[static_cast<PHILOSOPHER_ID>(i)] == NUMBER_OF_SERVINGS_PER_PHILOSOPHER);
        CHECK(status[static_cast<PHILOSOPHER_ID>(i)] == PHILOSOPHER_STATUS::THINKING);
    }      

    //Output the summary of all operations
    std::string output = "\nTHE DINING PHILOSOPHERS\n\n";
    output += "INPUT: n = " + std::to_string(NUMBER_OF_SERVINGS_PER_PHILOSOPHER) + "\n";
    output += "OUTPUT: [";    
    for (int i = 0; i < r.size(); i++) {
        if (i > 0) {
            output += ",";
        }
        output += "[" + std::to_string(std::get<0>(r[i])) + "," + std::to_string(std::get<1>(r[i])) + "," + std::to_string(std::get<2>(r[i])) + "]";        
    }
    output += "]";

    std::cout << output << std::endl;    
}