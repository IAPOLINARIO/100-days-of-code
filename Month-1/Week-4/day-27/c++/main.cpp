/**
 * DAY-27 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 * Example:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * 
 * Explanation:
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Update the tasks cooldown.
 * For the executed task, it resets its cooldown and for the others, it updates until 0.
 * @param cool The control map of tasks cooldown
 * @param executedTask The executed task.
 */ 
void updateCooldown(std::map<char, int>& cool, char& executedTask, int n) {
    for (auto iter = cool.begin(); iter != cool.end(); ++iter) {                    
        cool[iter->first] = (iter->first == executedTask) ? n : cool[iter->first] > 0 ? (cool[iter->first] - 1) : 0;                    
    }      
}

/**
 * Remove a task from the list of tasks.
 * @param tasks List of tasks of the CPU
 * @param t The task to remove from the list
 */ 
void removeTask(std::vector<char>& tasks, char& t) {
    auto it = std::find(tasks.begin(), tasks.end(), t);
    if (it != tasks.end()) {
        tasks.erase(it);
    }
}

/**
 * Return the least number of units of times that the CPU will take to finish all the given tasks.
 * @param tasks The tasks of the CPU
 * @param n The cooldown period between two same tasks
 * @return The least number of units of times that the CPU will take to finish all the given tasks
 */
int schedulerTimeUnits(std::vector<char> tasks, int n) {
    const char IDLE = '!';
    std::vector<char> executionPath;
    std::map<char, int> cooldownOp;   

    while (n > 0 && tasks.size() > 0) {        
        char taskScheduled;

        for (int i = 0; i < tasks.size(); i++) {
            taskScheduled = IDLE;            

            if (cooldownOp[tasks[i]] == 0) {
                executionPath.push_back(tasks[i]);
                updateCooldown(cooldownOp, tasks[i], n);
                taskScheduled = tasks[i];
                removeTask(tasks, tasks[i]);                
                break;
            } 
        }   
        
        if (taskScheduled == IDLE) {            
            executionPath.push_back(taskScheduled);            
            updateCooldown(cooldownOp, taskScheduled, n);                    
        }        
    }   

    return executionPath.size() > 0 ? executionPath.size() : tasks.size();
}

/**
 * Tests
 */
TEST_CASE("Tests")
{                                  
    CHECK(schedulerTimeUnits({'A','A','A','B','B','B'}, 0) == 6);
    CHECK(schedulerTimeUnits({'A','A','A','B','B','B'}, 2) == 8);
    CHECK(schedulerTimeUnits({'A','A','A','A','A','A','B','C','D','E','F','G'}, 2) == 16);
}