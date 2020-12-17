/**
 * DAY-26 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * A Briefcase Lock
 */ 
struct Lock {
    int data;
    Lock* next;
    Lock* back;

    //Constructor of Lock
    Lock(int data) {
        this->data = data;
    }

    /**
     * Resets the position of the Lock to the number specified.
     * @param n The number specified to reset position of the Lock
     * @return The Lock in the correct position
     */ 
    Lock* resetPosition(int n) {
        Lock* lock = this;
        while (lock->data != n) {
            lock = lock->next;
        }
        return lock;
    }
};

/**
 * Calculate the smallest number of turns it takes to transform the lock from the current combination to the target combination
 * @param current Current combination of lock
 * @param target Target combination of lock
 */
int MinTurns(std::string current, std::string target) {
    
    if (current.size() != target.size()) { //check if they current and target have the same size
        return -1;
    }    

    //setup Locks
    Lock *firstLock = new Lock(0);
    Lock *lock = firstLock;    
    for (int i = 1; i <= 9; i++) {
        Lock *newLock = new Lock(i);
        lock->next = newLock;
        newLock->back = lock;
        lock = lock->next;
    }
    firstLock->back = lock;
    lock->next = firstLock;

    int r = 0;
    for (int i = 0; i < current.size(); i++) {

        if (!isdigit(current[i]) || !isdigit(target[i])) { //check if they current and target have only digits
            return -1;
        }

        int curr = static_cast<int>(current[i] - '0');
        int targ = static_cast<int>(target[i] - '0');        

        lock = lock->resetPosition(curr);
        
        //try foward
        int countFoward = 0;
        while (lock->data != targ) {
            lock = lock->next;
            countFoward++;
        }

        lock = lock->resetPosition(curr);

        //try backward
        int countBackward = 0;
        while (lock->data != targ) {
            lock = lock->back;
            countBackward++;
        }

        //get the best path of rolling lock
        r += countFoward < countBackward ? countFoward : countBackward;        
    }

    //clean up the Locks
    lock = firstLock;    
    do  {
        Lock *toDelete = lock;        
        lock = lock->next;
        delete toDelete;
    } while (lock != firstLock);    
    
    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{                                  
    CHECK(MinTurns("2", "3") == 1);
    CHECK(MinTurns("4089", "5672") == 9);
    CHECK(MinTurns("1111", "1100") == 2);
    CHECK(MinTurns("2391", "4984") == 10);
    CHECK(MinTurns("223", "24") == -1); //test invalid input
    CHECK(MinTurns("321", "21A") == -1); //test invalid input
}