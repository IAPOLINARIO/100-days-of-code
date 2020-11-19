/**
 * DAY-21 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <stack> //for the stack to control the visited path

//Properties of a cell
enum ENUM_CELL_PROPERTIES {
    CELL_VISITED = 0x01,
    CELL_DOOR_NORTH = 0X02,
    CELL_DOOR_SOUTH = 0x04,
    CELL_DOOR_WEST = 0x08,
    CELL_DOOR_EAST = 0x10    
};

//Types of neighbors of a cell
enum ENUM_NEIGHBORS {
    NEIGHBOR_NORTH = 0,
    NEIGHBOR_SOUTH = 1,
    NEIGHBOR_WEST = 2,
    NEIGHBOR_EAST = 3
};

/**
 * Generates a maze.
 * @param width Width of the maze
 * @param height Height of the maze
 * @param seed Opcional seed for random number generator
 * @return the dynamically allocated maze pointer (it needs to be destroyed after use)
 */
int* generateMaze(int width, int height, int seed = 0) {    
    int *maze = new int[width * height]; //allocate memory to store the size of the maze in a pointer
    memset(maze, 0, width * height); //fill with zeroes
                    
    srand (seed != 0 ? seed : time(NULL)); // initialize random seed

    //select a random starting point in the maze
    int px = rand() % width;
    int py = rand() % height;
    
    maze[py * width + px] = CELL_VISITED; //mark the starting point as a visited cell
    int cellsVisited = 1; //count the number of cells visited

    //each visited cell is stored in a stack structure with the coordinates as a pair x, y
    std::stack<std::pair<int, int>> pathStack;
    pathStack.push(std::make_pair(px, py));

    //lambda to get the calculted position in the maze based on an offset applied to the current cell (top of the stack)
    auto offsetFromTopOfStack = [&](int x, int y) { return (pathStack.top().second + y) * width + (pathStack.top().first + x); };
        
    while (cellsVisited < width * height) { //repeat until all possible cells are visited
        std::vector<int> neighbors;       

        //from the current cell (top of the stack), look for all possibile unvisited neighbors (north, south, west, east)
        if (pathStack.top().second > 0 && (maze[offsetFromTopOfStack(0, -1)] & CELL_VISITED) == 0) {
            neighbors.push_back(NEIGHBOR_NORTH);
        }
        if (pathStack.top().second < height - 1 && (maze[offsetFromTopOfStack(0, 1)] & CELL_VISITED) == 0) {          
            neighbors.push_back(NEIGHBOR_SOUTH);
        }
        if (pathStack.top().first > 0 && (maze[offsetFromTopOfStack(-1, 0)] & CELL_VISITED) == 0) {
            neighbors.push_back(NEIGHBOR_WEST);
        }
        if (pathStack.top().first < width - 1 && (maze[offsetFromTopOfStack(1, 0)] & CELL_VISITED) == 0) {
            neighbors.push_back(NEIGHBOR_EAST);
        }        
        
        if (!neighbors.empty()) { //if there are at least one valid neighbor
            int nextNeighborDirection = neighbors[rand() % neighbors.size()]; //choose a random neighbor to visit
            
            /*-> Set 'door direction' bit to the current cell (offset 0,0).
              -> Set 'door direcion' to the next cell (offset variable depending on the direction), 
              thus creating a 'path' between them.
              -> Push the neighbor to the path stack to be the top/current cell.
              
              Although all 'door' flags are defined below, the rendering code just needs the NORTH and WEST,
              but they are set nonetheless, for a complete solution independent of the render code 
            */
            switch (nextNeighborDirection)
            {
            case NEIGHBOR_NORTH: 
                maze[offsetFromTopOfStack(0, 0)] |= CELL_VISITED |CELL_DOOR_NORTH;
                maze[offsetFromTopOfStack(0, -1)] |= CELL_VISITED | CELL_DOOR_SOUTH;                
                pathStack.push(std::make_pair(pathStack.top().first, pathStack.top().second - 1));
                break;
            case NEIGHBOR_SOUTH: 
                maze[offsetFromTopOfStack(0, 0)] |= CELL_VISITED |CELL_DOOR_SOUTH;
                maze[offsetFromTopOfStack(0, 1)] |= CELL_VISITED | CELL_DOOR_NORTH;                
                pathStack.push(std::make_pair(pathStack.top().first, pathStack.top().second + 1));
                break;                
            case NEIGHBOR_WEST:           
                maze[offsetFromTopOfStack(0, 0)] |= CELL_VISITED |CELL_DOOR_WEST;
                maze[offsetFromTopOfStack(-1, 0)] |= CELL_VISITED | CELL_DOOR_EAST;                
                pathStack.push(std::make_pair(pathStack.top().first - 1, pathStack.top().second));
                break;                                
            case NEIGHBOR_EAST:          
                maze[offsetFromTopOfStack(0, 0)] |= CELL_VISITED |CELL_DOOR_EAST;
                maze[offsetFromTopOfStack(1, 0)] |= CELL_VISITED | CELL_DOOR_WEST;                
                pathStack.push(std::make_pair(pathStack.top().first + 1, pathStack.top().second));
                break;                        
            }          
            cellsVisited++; //increment the number of visited cells
        } else {         
            pathStack.pop(); //go back to previous visited cell on the path stack if there are not any valid neighbors
        }
    }

    return maze; //return the dynamically allocated maze pointer
}

/**
 * Renders the maze.
 * @param maze Pointer to a maze structure
 * @param width Width of the maze
 * @param height Height of the maze
 * @return String representation of the maze
 */ 
std::string renderMaze(int* maze, int width, int height) {
    const int MAP_HEIGHT_INFLATE = 2; //Height inflated because each new cell is two characters vertically (the horizontal and vertical lines)

    //lambda to get the calculted position in the maze
    auto position = [&](int px, int py) { return ((py / 2) * width + px); };

    /*
     Go through all positions of the maze.
     The value of 'py' can go over the capacity of the maze (py <= height * 2). When that happens, 
     it will render the final horizontal line to close de bottom of the maze.
    */
    std::string r;
    for (int py = 0; py <= height * MAP_HEIGHT_INFLATE; py++) { 
        for (int px = 0; px < width; px++) {
            r += (py % 2 == 0) ? (((py != height * 2) && (maze[position(px, py)] & CELL_DOOR_NORTH) && (maze[position(px, py)] & CELL_VISITED)) ? (px == width -1) ?  "+   +" : "+   " : (px == width -1) ?  "+---+" : "+---") : (((maze[position(px, py)] & CELL_DOOR_WEST) && (maze[position(px, py)] & CELL_VISITED)) ? (px == width - 1) ?  "    |" : "    " : (px == width - 1) ?  "|   |" : "|   ");            
        }
        r += "\n";
    }

    return r;
}


TEST_CASE("Tests")
{                 
    const int MAZE_WIDTH = 20;
    const int MAZE_HEIGHT = 20;

    int visitedCells = 0;
    int doorsNorth = 0;
    int doorsSouth = 0;
    int doorsWest = 0;
    int doorsEast = 0;
    int *maze = generateMaze(MAZE_WIDTH, MAZE_HEIGHT);
    for (int py = 0; py < MAZE_HEIGHT; py++) {
        for (int px = 0; px < MAZE_WIDTH; px++) {
            int cell = maze[py * MAZE_WIDTH + px];
            visitedCells += (cell & CELL_VISITED) ? 1 : 0;
            doorsNorth += (cell & CELL_DOOR_NORTH) ? 1 : 0;
            doorsSouth += (cell & CELL_DOOR_SOUTH) ? 1 : 0;
            doorsWest += (cell & CELL_DOOR_WEST) ? 1 : 0;
            doorsEast += (cell & CELL_DOOR_EAST) ? 1 : 0;                         
        }
    }

    //number of visited cells must be MAP_WIDTH * MAP_HEIGHT
    CHECK(visitedCells == MAZE_WIDTH * MAZE_HEIGHT);

    //each cell must have at least one door
    CHECK(doorsNorth + doorsSouth + doorsWest + doorsEast >= visitedCells);        

    //render the maze and check its size
    std::string render = renderMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
    CHECK(render.size() == 3362); //for a MAZE_WIDTH x MAZE_HEIGHT maze

    std::cout << render;

    delete maze;        
}