/**
 * DAY-75 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <random>

/**
 * Build the Minesweeper.
 * @param size As size x size
 * @param mines Number of mines
 * @param seed Random seed (optional)
 * @return The field
 */ 
std::vector<int> buildMinesweeper(int size, int mines, int seed = 0) {    
    const int FIELD_SIZE = size * size; //calculate the size of the field

    if (mines > (FIELD_SIZE) || mines < 0 || size < 0) {
        return {}; //invalid input
    }

    //prepare the random number generator
    std::random_device rd;
    const unsigned long seedFinal = seed == 0 ? rd() : seed; //check seed    
    std::mt19937 engine(seedFinal); //start the engine
    
    //prepare the field to receive bombs in random positions
    std::vector<int> field(FIELD_SIZE, 1); //start with same 'weight chance' for each position
    for (int mine = 0 ; mine < mines; mine++) {           
        std::discrete_distribution<> dd(field.begin(), field.end());
        field[dd(engine)] = 0; //zero the chance for this position again
    }
    for (int i = 0; i < FIELD_SIZE; i++) {
        field[i] = (field[i] == 0) ? 9 : field[i]; //turn zeros into bombs
    }
    
    //possible neighbors of a cell
    const std::vector<std::vector<int>> neighborsOffset = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    //helper lambdas
    const auto calcPos = [&](const int &x, const int &y) { return y * size + x; };     
    const auto nearbyBombs = [&](const int &x, const int &y) {
        int b = 0;
        for (const auto &nOffset : neighborsOffset) {
            const auto absX = x + nOffset[0];
            const auto absY = y + nOffset[1];
            if (absX >= 0 && absX < size && absY >= 0 && absY < size && field[calcPos(absX, absY)] == 9) {
                b++;                
            }
        }
        return b;
    };    
    
    //print summary
    std::cout << "\n🔀 " << seedFinal << ", 🧱 " << size << " x " << size << ", 💣 " << mines << "\n\n"; 

    //Populate the Minesweeper and output at the same time
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {                        
            const int pos = calcPos(x, y);
            if (field[pos] != 9) {
                const int count = nearbyBombs(x, y);
                field[pos] = count;    
                std::cout << " " << field[pos] << " ";
            } else {
                std::cout << "💣 ";
            }            
            std::cout << "🧱 ";            
        }
        std::cout << '\n';
    }    
    
    return field; //return the Minesweeper
}

/**
 * Helper method to count number of bombs in the field
 * @param field the Minesweeper
 */ 
int countBombs(std::vector<int> field) {
    int b = 0;
    for (auto &c : field) {
        b += c == 9 ? 1 : 0;
    } 
    return b;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{        
    CHECK(countBombs(buildMinesweeper(4, 2)) == 2);
    CHECK(countBombs(buildMinesweeper(8, 32)) == 32);
    CHECK(countBombs(buildMinesweeper(10, 74)) == 74);
    CHECK(countBombs(buildMinesweeper(12, 50)) == 50);
    CHECK(countBombs(buildMinesweeper(15, 150)) == 150);
    CHECK(countBombs(buildMinesweeper(4, 50)) == 0); //invalid (bombs > capacity)
}


