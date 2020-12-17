/**
 * DAY-58 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <regex>
#include <random>


/**
 * Dice Roller
 * 
 * @param dices The dices vector in format <numberOfDices>d<numberOfSides>
 * @return string with a sum of dices rolls in format: <sum>: roll1 roll2 roll3 etc..
 */
std::string diceRoll(std::vector<std::string> dices) {
    std::string r;
    const std::string ERROR = "INVALID DICE(S)";
    const std::regex regexDices("(([0-9]{1,3})(d)([0-9]{1,3}))");
    std::smatch matches;        

    std::random_device rd; // only used once to initialise (seed) engine
    std::mt19937 rng(rd());// random-number engine used (Mersenne-Twister in this case)    

    for (auto &d : dices) {
        if (!std::regex_search(d, matches, regexDices)) {
            return ERROR;
        }        
        if (matches.size() != 5) {
            return ERROR;
        }
        
        int dices = atoi(matches[2].str().c_str());
        int sides = atoi(matches[4].str().c_str());

        std::uniform_int_distribution<int> uni(1, sides); // guaranteed unbiased

        int diceSum = 0;
        std::string rolls;
        for (int d = 0; d < dices; d++) {            
            auto roll = uni(rng);
            diceSum += roll;
            rolls += rolls.size() > 0 ? " " + std::to_string(roll) : std::to_string(roll);
        }

        if (r.size() > 0) {
            r += '\n';
        }

        r +=  std::to_string(diceSum) + ": " + rolls;
    }

    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    const std::vector<std::string> dices = {"3d6", "1d10", "5d4", "100d100"};
    const std::string r = diceRoll(dices);

    int count = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] == ':') {
            count ++;
        }
    }

    CHECK(count == dices.size());

    CHECK(diceRoll({"D200"}) == "INVALID DICE(S)");
}





