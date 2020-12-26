/**
 * DAY-79 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

enum CLOCK_INDICATOR_DIRECTION {U, D, L, R, LU, LD, RU, RD};
static const int CLOCK_WIDTH = 25;
static const std::pair<int, int> CLOCK_CENTER(11, 6);  
static const std::string CLOCK_FRAME = 
R"(+- ZZ:ZZ - - - - - - - +
|      . . 12. .       |
|    11          1     |
|  10              2   |
|.                   . |
|.                   . |
|9                   3 |
|.                   . |
|.                   . |
|  8               4   |
|    7           5     |
|      . . 6 . .       |
+- - - - - - - - - - - +)";

static std::map<int, std::array<CLOCK_INDICATOR_DIRECTION, 4>> CLOCK_INDICATOR = {
    {0, {U, U, U, U}},
    {1, {R, RU, RU, RU}},
    {2, {R, RU, R, RU}},
    {3, {R, R, R, R}},
    {4, {R, RD, R, RD}},
    {5, {R, RD, RD, RD}},
    {6, {D, D, D, D}},
    {7, {L, LD, LD, LD}},
    {8, {L, LD, L, LD}},
    {9, {L, L, L, L}},
    {10, {L, LU, L, LU}},
    {11, {L, LU, LU, LU}}    
};    

static const std::array<int, 12> CLOCK_MINUTES = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};

/**
 * Update the analog indicator of the clock
 * @param clock The clock
 * @param i Indicator Data
 * @param iType Indicator Type
 */ 
void updateIndicator(std::string &clock, const std::array<CLOCK_INDICATOR_DIRECTION, 4> &i, char iType) {
    std::pair<int, int> ref = CLOCK_CENTER;
    for (auto &d : i) {
        switch (d)
        {
        case U: ref.second--; break;
        case D: ref.second++; break;
        case L: ref.first--; ref.first--; break;
        case R: ref.first++; ref.first++; break;
        case RU: ref.first++; ref.second--; break;
        case RD: ref.first++; ref.second++; break;
        case LU: ref.first--; ref.second--; break;
        case LD: ref.first--; ref.second++; break;
        }
        const auto pos = ref.second * CLOCK_WIDTH + ref.first;
        if (clock[pos] == ' ') {
            clock[pos] = iType;
        }
    }
}

/**
 * Update the digital time of the clock frame
 * @param clock The clock
 * @param hInput Hour
 * @param mInput Minute
 */ 
void updateDigital(std::string &clock, int hInput, int mInput) {
    std::stringstream ssH;
    ssH << std::setw(2) << std::setfill('0') << hInput;
    std::stringstream ssM;
    ssM << std::setw(2) << std::setfill('0') << mInput;
    clock[3] = ssH.str()[0];
    clock[4] = ssH.str()[1];
    clock[6] = ssM.str()[0];
    clock[7] = ssM.str()[1];
}

/**
 * Terminal Analog Clock (5 minute resolution)
 * @param hInput Hour (optional)
 * @param mInput Minute (optional)
 * @return Analog Clock representation
 */ 
std::string analogClock(int hInput = -1, int mInput = -1) {
    //check if there is input
    if (hInput < 0 || mInput < 0) {
        //no input detected, get the current time (hour and minute)
        time_t currentTime;
        struct tm *localTime;
        time( &currentTime );
        localTime = localtime(&currentTime);
        hInput = localTime->tm_hour;
        mInput = localTime->tm_min;        
    }    
    
    std::string clock = CLOCK_FRAME;  //get the base clock frame
    updateDigital(clock, hInput, mInput); //update the digital time of the clock frame

    if (hInput > 11) {
        hInput = hInput - 12; //handle hours above 11
    }
    
    //since this is a 5-minute resolution clock (defined in the challenge), get the closest minute
    int distance = INT_MAX;
    int minutesIndex = 0;
    for (int i = 0; i < CLOCK_MINUTES.size(); i++) {
        const int distanceAux = abs(CLOCK_MINUTES[i] - mInput);
        if (distanceAux < distance) {
            distance = distanceAux;            
            minutesIndex = i;
        }
    } 
    
    updateIndicator(clock, CLOCK_INDICATOR[hInput], 'H'); //update the hour indicator
    updateIndicator(clock, CLOCK_INDICATOR[minutesIndex], 'M'); //update the minute indicator
    
    std::cout <<'\n' << clock << '\n' << std::endl; //print clock

    return clock;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(analogClock(23, 36) == 
R"(+- 23:36 - - - - - - - +
|      . . 12. .       |
|    11          1     |
|  10 H            2   |
|.     H             . |
|.      H            . |
|9       H           3 |
|.      M            . |
|.     M             . |
|  8  M            4   |
|    7           5     |
|      . . 6 . .       |
+- - - - - - - - - - - +)");

    CHECK(analogClock(15, 00) == 
R"(+- 15:00 - - - - - - - +
|      . . 12. .       |
|    11    M     1     |
|  10      M       2   |
|.         M         . |
|.         M         . |
|9           H H H H 3 |
|.                   . |
|.                   . |
|  8               4   |
|    7           5     |
|      . . 6 . .       |
+- - - - - - - - - - - +)");

    CHECK(analogClock(00, 00) == 
R"(+- 00:00 - - - - - - - +
|      . . 12. .       |
|    11    H     1     |
|  10      H       2   |
|.         H         . |
|.         H         . |
|9                   3 |
|.                   . |
|.                   . |
|  8               4   |
|    7           5     |
|      . . 6 . .       |
+- - - - - - - - - - - +)");
}