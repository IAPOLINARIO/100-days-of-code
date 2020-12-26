/**
 * DAY-77 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

enum SAVE_MOVEMENT {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

/**
 * Bot saves princess
 * @param size Grid size (as size x size)
 * @param botR Position of bot (row)
 * @param botC Position of bot (column)
 * @param grid The grid
 * @param Vector of save movements
 */ 
std::vector<SAVE_MOVEMENT> botSavePrincess(int size, int botR, int botC, std::vector<std::vector<char>> grid) {
    std::vector<SAVE_MOVEMENT> r;

    //check for invalid parameters
    if (size <= 0 || grid.size() != size || grid[0].size() != size || botR >= size || botC >= size || botR < 0 || botC < 0) {
        return r; //invalid input - STOP NOW
    }    

    //detect Princess position in the grid (one and only one is allowed - check for this as well)
    //also check for the bot position on the grid, it needs to be the same as the parameters
    int princessCount = 0;    
    int pR;
    int pC;
    int botCount = 0;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (grid[j][i] == 'p') {
                princessCount++;
                pR = j;
                pC = i;
            } else {
                if (grid[j][i] == 'm') {
                    botCount++;
                    if (j != botR || i != botC) {
                        return r; //invalid bot position in the grid - STOP NOW
                    }
                } else {
                    if (grid[j][i] != '-') {
                        return r; //invalid content in the grid - STOP NOW
                    }
                }
                
            }
        }
    }

    if (princessCount != 1 || botCount != 1) {
        return r; //invalid princess or bot data - STOP NOW
    }

    //after this, we FINALLY know the parameters are OK...        
    int horizontalMov = pC - botC;
    int verticalMov = pR - botR;
    for (int i = 0; i < abs(horizontalMov); i++) {
        r.push_back(horizontalMov > 0 ? SAVE_MOVEMENT::RIGHT : SAVE_MOVEMENT::LEFT);
    }
    for (int j = 0; j < abs(verticalMov); j++) {
        r.push_back(horizontalMov > 0 ? SAVE_MOVEMENT::DOWN : SAVE_MOVEMENT::UP);
    }

    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    auto path = botSavePrincess(5, 2, 3, {{'-','-','-','-','-'},
                                          {'-','-','-','-','-'},
                                          {'p','-','-','m','-'},
                                          {'-','-','-','-','-'},
                                          {'-','-','-','-','-'}});
    int countLeft = 0;
    for (auto &p : path) {
        CHECK(p == SAVE_MOVEMENT::LEFT);
        countLeft++;
    }
    CHECK(countLeft == 3);

    path = botSavePrincess(5, 4, 4, {{'-','-','-','-','-'},
                                     {'-','-','-','-','-'},
                                     {'p','-','-','-','-'},
                                     {'-','-','-','-','-'},
                                     {'-','-','-','-','m'}});
    countLeft = 0;
    int countUp = 0;
    for (auto &p : path) {
        CHECK_FALSE(!(p == SAVE_MOVEMENT::LEFT || p == SAVE_MOVEMENT::UP));
        switch (p)
        {
        case SAVE_MOVEMENT::LEFT:
            countLeft++;
            break;
        case SAVE_MOVEMENT::UP:
            countUp++;
            break;        
        default:
           // FAIL(p);
            break;
        }        
    }
    CHECK(countLeft == 4);
    CHECK(countUp == 2);

    path = botSavePrincess(5, 2, 0, {{'-','-','-','-','-'},
                                     {'-','-','-','-','-'},
                                     {'m','-','-','-','-'},
                                     {'-','-','-','-','-'},
                                     {'-','-','-','-','p'}});

    int countRight = 0;
    int countDown = 0;
    for (auto &p : path) {
        CHECK_FALSE(!(p == SAVE_MOVEMENT::RIGHT || p == SAVE_MOVEMENT::DOWN));
        switch (p)
        {
        case SAVE_MOVEMENT::RIGHT:
            countRight++;
            break;
        case SAVE_MOVEMENT::DOWN:
            countDown++;
            break;        
        default:
            FAIL(p);
            break;
        }        
    }
    CHECK(countRight == 4);
    CHECK(countDown == 2);            

    //invalid bot position when compared to the parameters of the method defined in the challenge...
    CHECK(botSavePrincess(5, 2, 0, {{'-','-','-','-','-'},
                                    {'-','-','-','-','-'},
                                    {'-','m','-','-','-'}, 
                                    {'-','-','-','-','-'},
                                    {'-','-','-','-','p'}}).size() == 0);


    //invalid princess data
    CHECK(botSavePrincess(5, 2, 0, {{'-','-','-','-','-'},
                                    {'-','-','p','-','-'},
                                    {'-','m','-','-','-'}, 
                                    {'-','-','-','-','-'},
                                    {'-','-','-','-','p'}}).size() == 0);

}