/**
 * DAY-29 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Check the Traffic Light input
 * @lights The traffic light input
 * @return ACCEPT, REJECT or ERROR
 */ 
std::string trafficLightChecker(std::string lights) {        
    const std::string ACCEPT = "ACCEPT";
    const std::string REJECT = "REJECT";
    const std::string ERROR = "ERROR";     
    const std::vector<char> VALID_LIGHTS = {'R', 'G', 'Y'};
    const std::vector<char> VALID_FLASHES = {'C', 'P'};
    const char INTERVAL = ' ';
    const char OFF = 'X';
    const int MIN_SIZE = 6;
    const int MAX_SIZE = 30;

    if (lights.size() < MIN_SIZE || lights.size() > MAX_SIZE) {
        return ERROR;
    }

    //Check for only valid codes
    for (int i = 0; i < lights.size(); i++) {        
        if (i % 2 != 0) {
            if (lights[i] != INTERVAL) {
                return ERROR;
            }              
        } else {
            if (lights[i] != OFF && std::find(VALID_LIGHTS.begin(), VALID_LIGHTS.end(), lights[i]) == VALID_LIGHTS.end() && std::find(VALID_FLASHES.begin(), VALID_FLASHES.end(), lights[i]) == VALID_FLASHES.end()) {
                return ERROR;
            }
        }
    }

    //Must start with a RED
    if (lights[0] != VALID_LIGHTS[0]) {
        return REJECT;
    }
    
    for (int i = 1; i < lights.size(); i++) {
        //Ignore valid intervals
        if (lights[i] == INTERVAL) {
            continue;
        }

        bool isFlash = std::find(VALID_FLASHES.begin(), VALID_FLASHES.end(), lights[i]) != VALID_FLASHES.end();

        int lightIndex = -1;
        auto it = std::find(VALID_LIGHTS.begin(), VALID_LIGHTS.end(), lights[i]);
        if (it != VALID_LIGHTS.end()) {
            lightIndex = it - VALID_LIGHTS.begin();
        }
        
        //OFF (if it exists) must be the final command
        if (i != (lights.size() - 1) && lights[i] == OFF) {
            return REJECT;
        }

        //Either flash sequence may only be started after the red light is lit and must be followed with a red
        if ((isFlash && lights.size() < 3) || (isFlash && i == 0) || (isFlash && i == lights.size() -1) || (isFlash && (lights[i - 2] != lights[0] || lights[i + 2] != lights[0]))) {
            return REJECT;
        }

        //If it is a valid Light Code, check if it is in correct sequence order
        if (lightIndex > 0 && lights[i - 2] != VALID_LIGHTS[lightIndex - 1] ) {
            return REJECT;            
        }
    }

    return ACCEPT;
}


/**
 * Tests
 */
TEST_CASE("Tests")
{     
    CHECK(trafficLightChecker("R G Y R C R G Y R") == "ACCEPT");
    CHECK(trafficLightChecker("R G Y R C R G Y R X") == "ACCEPT");
    CHECK(trafficLightChecker("G Y R G Y R") == "REJECT");
    CHECK(trafficLightChecker("R Y G P") == "REJECT");    
    CHECK(trafficLightChecker("R G Y") == "ERROR");
    CHECK(trafficLightChecker("X 8 S") == "ERROR");
    CHECK(trafficLightChecker("R G Y R C R P R G Y R G Y R G Y R") == "ERROR");
}