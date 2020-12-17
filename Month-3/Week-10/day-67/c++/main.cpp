/**
 * DAY-67 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Color target to follow
 */ 
struct ColorTarget {
    char value;
    ColorTarget* next;    
    ColorTarget(char value) {
        this->value = value;        
    }    
};

/**
 * Valid directions
 */ 
enum DIRECTIONS {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ALL,
    CLEAR
};

/**
 * Structure to hold partial and final results
 */ 
struct Result {
    ColorTarget* colorTarget;
    std::vector<std::pair<int, int>> pathUntilNow;
    DIRECTIONS noWay;
};

/**
 * Found the exit?
 * @param path The path
 * @return true if finished maze
 */ 
bool foundExit(std::vector<std::pair<int, int>> path) {
    return path.size() > 0 && path[path.size() - 1].second == 0;
}

/**
 * Are we at a dead end?
 * @param pathUntilNow The chosen path until now
 * @para noWayLimit How many times a path can be repeated?
 * @return true if we hit a dead end
 */ 
bool noWay(std::vector<std::pair<int, int>> &pathUntilNow, const int noWayLimit) {
    std::map<std::pair<int, int>, int> pm;    
    for (int i = pathUntilNow.size() - 1; i >= 0; i--) {
        pm[pathUntilNow[i]] = pm.find(pathUntilNow[i]) == pm.end() ? 1 : pm[pathUntilNow[i]] + 1;
        if (pm[pathUntilNow[i]] > noWayLimit) {            
            return true;
        }
    }
    return false;
}

/**
 * Go find the exit of the maze
 * @param noWayLimit How many times a path can be repeated?
 * @param maze The maze
 * @param startingPoint The starting point
 * @param path The chosen path until now
 * @param colorChoices History of colors selected
 * @param nwDir 'No way' direction, direction not allowed anymore
 * @return Result structure
 */ 
Result go(const int &noWayLimit,
        ColorTarget *color, 
        std::vector<std::vector<char>> &maze, 
        std::pair<int, int> startingPoint,
        std::vector<std::pair<int, int>> path,
        std::vector<ColorTarget*> &colorChoices,
        DIRECTIONS nwDir) {

    path.push_back(startingPoint);
    colorChoices.push_back(color);
                
    Result result;
    result.pathUntilNow = path;
    result.colorTarget = color;
    result.noWay = nwDir;
    
    //check possible direction: up
    if (result.noWay != DIRECTIONS::ALL && result.noWay != DIRECTIONS::UP && !noWay(result.pathUntilNow, noWayLimit) && !foundExit(result.pathUntilNow) && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first] == result.colorTarget->value && result.pathUntilNow.back().second > 0 && maze[result.pathUntilNow.back().second - 1][result.pathUntilNow.back().first] == result.colorTarget->next->value) {            
        if (result.noWay == DIRECTIONS::LEFT || result.noWay == DIRECTIONS::RIGHT) {
            result.noWay = DIRECTIONS::CLEAR;
        }
        result = go(noWayLimit, result.colorTarget->next, maze, std::make_pair(result.pathUntilNow.back().first, startingPoint.second - 1), result.pathUntilNow, colorChoices, result.noWay);
    }        
    
    //check possible direction: left
    if (result.noWay != DIRECTIONS::ALL && result.noWay != DIRECTIONS::LEFT && !noWay(result.pathUntilNow, noWayLimit) && !foundExit(result.pathUntilNow) && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first] == result.colorTarget->value &&  result.pathUntilNow.back().first > 0 && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first - 1] == result.colorTarget->next->value) {
        if (result.noWay == DIRECTIONS::UP || result.noWay == DIRECTIONS::DOWN) {
            result.noWay = DIRECTIONS::CLEAR;
        }
        result = go(noWayLimit, result.colorTarget->next, maze, std::make_pair(result.pathUntilNow.back().first - 1, result.pathUntilNow.back().second), result.pathUntilNow, colorChoices, result.noWay);
    }

    //check possible direction: right
    if (result.noWay != DIRECTIONS::ALL && result.noWay != DIRECTIONS::RIGHT && !noWay(result.pathUntilNow, noWayLimit) && !foundExit(result.pathUntilNow) && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first] == result.colorTarget->value && result.pathUntilNow.back().first < (maze[result.pathUntilNow.back().second].size() - 1) && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first + 1] == result.colorTarget->next->value) {
        if (result.noWay == DIRECTIONS::UP || result.noWay == DIRECTIONS::DOWN) {
            result.noWay = DIRECTIONS::CLEAR;
        }
        result = go(noWayLimit, result.colorTarget->next, maze, std::make_pair(result.pathUntilNow.back().first + 1, result.pathUntilNow.back().second), result.pathUntilNow, colorChoices, result.noWay);
    }

    //check possible direction: down
    if (result.noWay != DIRECTIONS::ALL && result.noWay != DIRECTIONS::DOWN && !noWay(result.pathUntilNow, noWayLimit) && !foundExit(result.pathUntilNow) && maze[result.pathUntilNow.back().second][result.pathUntilNow.back().first] == result.colorTarget->value && result.pathUntilNow.back().second < (maze[result.pathUntilNow.back().second].size() - 1) && maze[result.pathUntilNow.back().second + 1][result.pathUntilNow.back().first] == result.colorTarget->next->value) {
        if (result.noWay == DIRECTIONS::LEFT || result.noWay == DIRECTIONS::RIGHT) {
            result.noWay = DIRECTIONS::CLEAR;
        }
        result = go(noWayLimit, result.colorTarget->next, maze, std::make_pair(result.pathUntilNow.back().first, result.pathUntilNow.back().second + 1), result.pathUntilNow, colorChoices, result.noWay);
    }        
            
    if (!result.pathUntilNow.empty() && !foundExit(result.pathUntilNow)) {             
        if (noWay(result.pathUntilNow, noWayLimit)) { //handle a 'no way' path, to try another  
            //cut the 'no way' path, to start new approach if possible          
            const int oddIncrement = result.pathUntilNow.size() % 2 != 0 ? 1 : 0;
            const int resize = result.pathUntilNow.size() - ((noWayLimit * 2)) + oddIncrement;
            result.pathUntilNow.resize(resize);

            if (result.pathUntilNow.size() <= 2) {
                result.noWay = DIRECTIONS::ALL; //give up
            } else {
                std::pair<int, int> p1 = result.pathUntilNow[result.pathUntilNow.size() - 2];
                std::pair<int, int> p2 = result.pathUntilNow.back();

                if ((p2.first - p1.first) > 0) {
                    result.noWay = oddIncrement > 0 ? DIRECTIONS::LEFT : DIRECTIONS::RIGHT;
                } else {
                    if ((p2.first - p1.first) < 0) {                        
                        result.noWay = oddIncrement > 0 ? DIRECTIONS::RIGHT : DIRECTIONS::LEFT;
                    } else {
                        if ((p2.second - p1.second) > 0) {                            
                            result.noWay = oddIncrement > 0 ? DIRECTIONS::UP : DIRECTIONS::DOWN;
                        } else {                            
                            result.noWay = oddIncrement > 0 ? DIRECTIONS::DOWN : DIRECTIONS::UP;
                        }
                    }
                }  
            }   
            for (int i = 0; i < ((noWayLimit * 2) + oddIncrement); i++) {
                colorChoices.pop_back(); //rewind color sequence
            }                        
        } else {
            result.pathUntilNow.pop_back();
            colorChoices.pop_back();            
        }
        result.colorTarget = colorChoices.back();
    } 
    
    return result;
}

/**
 * Print condititions and solution.
 * @param colorSequence Color sequence to follow
 * @param maze The maze
 * @param r The end result
 */ 
void printResults(std::vector<char> &colorSequence, std::vector<std::vector<char>> &maze, Result &r) {    
    std::cout << "\n--------------------------------------------------------------------------------";
    std::cout << "\n\nCOLOR SEQUENCE:";
    for (auto &c : colorSequence) {
        std::cout << " " << c;
    }
    std::cout << "\n\nMAZE:\n";
    std::cout << "[\n";
    for (int j = 0; j < maze.size(); j++) {
        for (int i = 0; i < maze[j].size(); i++) {
            std::cout << "  " << maze[j][i];
        }
        std::cout << "\n";
    }
    std::cout << ']';

    std::cout << "\n\nSOLUTION:";
    if (r.pathUntilNow.size() > 0) {
        std::cout << "\n";
        for (auto &p : r.pathUntilNow) {
            std::cout << "(" << std::to_string(p.first) << ", " << std::to_string(p.second) << ")" << std::endl;
        }
    } else {
        std::cout << " NO SOLUTION!";
    }    
}

/**
 * Entry point - Color Maze
 * @param colorSequence Color Sequence to follow
 * @param maze The maze
 * @param Solution as a vector of coordinates X and Y of each step
 */ 
std::vector<std::pair<int, int>> colorMaze(std::vector<char> colorSequence, std::vector<std::vector<char>> maze) {    
    if (colorSequence.size() == 0) { //invalid input - no color sequence
        return {};
    }
       
    //build the color sequence
    std::vector<ColorTarget> colorTargetManager;
    for (auto &c : colorSequence) {
        ColorTarget colorTarget(c);              
        colorTargetManager.push_back(colorTarget);        
    }    
    for (size_t i = 0; i < colorTargetManager.size() - 1; i++) {
        colorTargetManager[i].next = &colorTargetManager[i + 1];        
    }
    colorTargetManager[colorTargetManager.size() - 1].next = &colorTargetManager[0];            
    std::vector<ColorTarget*> colorChoices;     

    Result r;    
    for (size_t i = 0; i < maze[maze.size() - 1].size() && !foundExit(r.pathUntilNow); i++) {
        r = go(colorTargetManager.size() * 2, &colorTargetManager[0], maze, std::make_pair(i, maze.size() - 1), {}, colorChoices, DIRECTIONS::CLEAR);
    }

    printResults(colorSequence, maze, r);

    return r.pathUntilNow;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{          
    CHECK(colorMaze({'R', 'W'}, {{'R', 'O', 'G'},
                                 {'W', 'R', 'W'},
                                 {'G', 'O', 'R'},
                                 {'O', 'R', 'W'}}) 
                                 == std::vector<std::pair<int, int>>{
                                     std::make_pair(1,3),
                                     std::make_pair(2,3),
                                     std::make_pair(2,2),
                                     std::make_pair(2,1),
                                     std::make_pair(1,1),
                                     std::make_pair(0,1),
                                     std::make_pair(0,0)                                     
                                 });

    CHECK(colorMaze({'R', 'W'}, {{'R', 'O', 'G'},
                                 {'W', 'R', 'W'},
                                 {'G', 'O', 'O'},
                                 {'O', 'R', 'W'}}) 
                                == std::vector<std::pair<int, int>>{}); //impossible maze
  
    CHECK(colorMaze({'O', 'G'}, {{'C', 'O', 'R', 'O', 'Y'},
                                 {'O', 'R', 'V', 'G', 'R'},
                                 {'G', 'O', 'G', 'O', 'G'},
                                 {'Y', 'G', 'B', 'Y', 'G'},
                                 {'R', 'O', 'R', 'B', 'R'}}) 
                                 == std::vector<std::pair<int, int>>{
                                     std::make_pair(1,4),
                                     std::make_pair(1,3),
                                     std::make_pair(1,2),
                                     std::make_pair(2,2),
                                     std::make_pair(3,2),
                                     std::make_pair(3,1),
                                     std::make_pair(3,0)
                                 });         
                                                                     
    CHECK(colorMaze({'O', 'G'}, {{'B', 'O', 'R', 'O', 'Y'},
                                 {'O', 'R', 'B', 'G', 'R'},
                                 {'B', 'O', 'G', 'O', 'Y'},
                                 {'Y', 'G', 'B', 'Y', 'G'},
                                 {'R', 'O', 'R', 'B', 'R'}}) 
                                 == std::vector<std::pair<int, int>>{
                                     std::make_pair(1,4),
                                     std::make_pair(1,3),
                                     std::make_pair(1,2),
                                     std::make_pair(2,2),
                                     std::make_pair(3,2),
                                     std::make_pair(3,1),
                                     std::make_pair(3,0)                                     
                                 });

    CHECK(colorMaze({'O', 'G'}, {{'G', 'O', 'R', 'O', 'Y'},
                                 {'O', 'R', 'B', 'C', 'R'},
                                 {'G', 'O', 'G', 'O', 'G'},
                                 {'Y', 'G', 'B', 'Y', 'G'},
                                 {'R', 'O', 'R', 'B', 'R'}}) 
                                 == std::vector<std::pair<int, int>>{
                                     std::make_pair(1,4),
                                     std::make_pair(1,3),
                                     std::make_pair(1,2),
                                     std::make_pair(0,2),
                                     std::make_pair(0,1),
                                     std::make_pair(0,0)                                     
                                 });                                       

    CHECK(colorMaze({'R', 'O', 'Y', 'P', 'O'}, {
                    {'R', 'R', 'B', 'R', 'R', 'R', 'B', 'P', 'Y', 'G', 'P', 'B', 'B', 'B', 'G', 'P', 'B', 'P', 'P', 'R'},
                    {'B', 'G', 'Y', 'P', 'R', 'P', 'Y', 'Y', 'O', 'R', 'Y', 'P', 'P', 'Y', 'Y', 'R', 'R', 'R', 'P', 'P'},
                    {'B', 'P', 'G', 'R', 'O', 'P', 'Y', 'G', 'R', 'Y', 'Y', 'G', 'P', 'O', 'R', 'Y', 'P', 'B', 'O', 'O'},
                    {'R', 'B', 'B', 'O', 'R', 'P', 'Y', 'O', 'O', 'Y', 'R', 'P', 'B', 'R', 'G', 'R', 'B', 'G', 'P', 'G'},
                    {'R', 'P', 'Y', 'G', 'G', 'G', 'P', 'Y', 'P', 'Y', 'O', 'G', 'B', 'O', 'R', 'Y', 'P', 'B', 'Y', 'O'},
                    {'O', 'R', 'B', 'G', 'B', 'Y', 'B', 'P', 'G', 'R', 'P', 'Y', 'R', 'O', 'G', 'Y', 'G', 'Y', 'R', 'P'},
                    {'B', 'G', 'O', 'O', 'O', 'G', 'B', 'B', 'R', 'O', 'Y', 'Y', 'Y', 'Y', 'P', 'B', 'Y', 'Y', 'G', 'G'},
                    {'P', 'P', 'G', 'B', 'O', 'P', 'Y', 'G', 'B', 'R', 'O', 'G', 'B', 'G', 'R', 'O', 'Y', 'R', 'B', 'R'},
                    {'Y', 'Y', 'P', 'P', 'R', 'B', 'Y', 'B', 'P', 'O', 'O', 'G', 'P', 'Y', 'R', 'P', 'P', 'Y', 'R', 'Y'},
                    {'P', 'O', 'O', 'B', 'B', 'B', 'G', 'O', 'Y', 'G', 'O', 'P', 'B', 'G', 'Y', 'R', 'R', 'Y', 'R', 'B'},
                    {'P', 'P', 'Y', 'R', 'B', 'O', 'O', 'R', 'O', 'R', 'Y', 'B', 'G', 'B', 'G', 'O', 'O', 'P', 'B', 'Y'},
                    {'B', 'B', 'R', 'G', 'Y', 'G', 'P', 'Y', 'G', 'P', 'R', 'R', 'P', 'Y', 'G', 'O', 'O', 'Y', 'R', 'R'},
                    {'O', 'G', 'R', 'Y', 'B', 'P', 'Y', 'O', 'P', 'B', 'R', 'Y', 'B', 'G', 'P', 'G', 'O', 'O', 'B', 'P'},
                    {'R', 'Y', 'G', 'P', 'G', 'G', 'O', 'R', 'Y', 'O', 'O', 'G', 'R', 'G', 'P', 'P', 'Y', 'P', 'B', 'G'},
                    {'P', 'Y', 'P', 'R', 'O', 'O', 'R', 'O', 'Y', 'R', 'P', 'O', 'R', 'Y', 'P', 'Y', 'B', 'B', 'Y', 'R'},
                    {'O', 'Y', 'P', 'G', 'R', 'P', 'R', 'G', 'P', 'O', 'B', 'B', 'R', 'B', 'O', 'B', 'Y', 'Y', 'B', 'P'},
                    {'B', 'Y', 'Y', 'P', 'O', 'Y', 'O', 'Y', 'O', 'R', 'B', 'R', 'G', 'G', 'Y', 'G', 'R', 'G', 'Y', 'G'},
                    {'Y', 'B', 'Y', 'Y', 'G', 'B', 'R', 'R', 'O', 'B', 'O', 'P', 'P', 'O', 'B', 'O', 'R', 'R', 'R', 'P'},
                    {'P', 'O', 'O', 'O', 'P', 'Y', 'G', 'G', 'Y', 'P', 'O', 'G', 'P', 'O', 'B', 'G', 'P', 'R', 'P', 'B'},
                    {'R', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'Y', 'O', 'B', 'G', 'P', 'G', 'G', 'O', 'O', 'Y'}})
                    == std::vector<std::pair<int, int>>
                                {
                                    std::make_pair(3, 19),
                                    std::make_pair(3, 18),
                                    std::make_pair(3, 17),
                                    std::make_pair(3, 16),
                                    std::make_pair(4, 16),
                                    std::make_pair(4, 15),
                                    std::make_pair(4, 16),
                                    std::make_pair(5, 16),
                                    std::make_pair(5, 15),
                                    std::make_pair(5, 14),
                                    std::make_pair(6, 14),
                                    std::make_pair(6, 13),
                                    std::make_pair(6, 12),
                                    std::make_pair(6, 11),
                                    std::make_pair(6, 10),
                                    std::make_pair(7, 10),
                                    std::make_pair(7, 9),
                                    std::make_pair(8, 9),
                                    std::make_pair(8, 8),
                                    std::make_pair(9, 8),
                                    std::make_pair(9, 7),
                                    std::make_pair(9, 6),
                                    std::make_pair(10, 6),
                                    std::make_pair(10, 5),
                                    std::make_pair(10, 4),
                                    std::make_pair(10, 3),
                                    std::make_pair(10, 4),
                                    std::make_pair(9, 4),
                                    std::make_pair(8, 4),
                                    std::make_pair(8, 3),
                                    std::make_pair(8, 2),
                                    std::make_pair(8, 1),
                                    std::make_pair(8, 0)
                                });
}