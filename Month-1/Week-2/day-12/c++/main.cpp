/**
 * DAY-12 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 *  Detect terrain type: "mountain", "valley", or "neither".
 *  @param t vector of terrain description
 *  @return terrain type
 */
std::string detectTerrainType(std::vector<int> t)
{
    std::string r = "neither";
        
    //detect peak
    int peak = t[0];
    bool canBeMontain = false;
    int peakIndex = 0;
    for (int i = 1; i < t.size() -1; i++) {
        if (t[i] > peak) {
            peak = t[i];
            canBeMontain = true;
            peakIndex = i;
        } else {
            if (t[i] == peak) {
                canBeMontain = false;
            }            
        }
    }
    
    int refValue = peak;
    if (canBeMontain) {
        for (int i = peakIndex + 1; i < t.size(); i++) {
            if (t[i] <= refValue) {
                refValue = t[i];
            } else {
                canBeMontain = false;
                break;
            }
        }
        if (canBeMontain) {
            refValue = peak;            
            for (int i = peakIndex -1; i >= 0; i--) {
                if (t[i] <= refValue) {
                    refValue = t[i];
                } else {
                    canBeMontain = false;
                    break;
                }
            }   
        }
    }

    if (canBeMontain) {
        return "montain";
    } else {
        //detect trough
        int trough = t[0];
        bool canBeValley = false;
        int troughIndex = 0;
        for (int i = 1; i < t.size() -1; i++) {
            if (t[i] < trough) {
                trough = t[i];
                canBeValley = true;
                troughIndex = i;
            } else {
                if (t[i] == trough) {
                    canBeValley = false;
                }            
            }
        }
        
        int refValue = trough;
        if (canBeValley) {
            for (int i = troughIndex + 1; i < t.size(); i++) {
                if (t[i] >= refValue) {
                    refValue = t[i];
                } else {
                    canBeValley = false;                    
                    break;
                }
            }
            if (canBeValley) {
                refValue = trough;
                for (int i = troughIndex -1; i >= 0; i--) {
                    if (t[i] >= refValue) {
                        refValue = t[i];
                    } else {
                        canBeValley = false;                        
                        break;
                    }
                }   
            }
        }

        if (canBeValley) {
            return "valley";
        }        
    }

    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(detectTerrainType({-1, 0, -1}) == "montain");    
    CHECK(detectTerrainType({-1, -1, 0, -1, -1}) == "montain");    
    CHECK(detectTerrainType({3, 4, 5, 4, 3}) == "montain");    
    CHECK(detectTerrainType({1, 3, 5, 4, 3, 2}) == "montain");

    CHECK(detectTerrainType({10, 9, 8, 7, 2, 3, 4, 5}) == "valley");  
    CHECK(detectTerrainType({350, 100, 200, 400, 700}) == "valley");  
    CHECK(detectTerrainType({9, 7, 3, 1, 2, 4}) == "valley");  
    CHECK(detectTerrainType({9, 8, 9}) == "valley");

    CHECK(detectTerrainType({1, 2, 3, 2, 4, 1}) == "neither");  
    CHECK(detectTerrainType({5, 4, 3, 2, 1}) == "neither");  
    CHECK(detectTerrainType({0, -1, -1, 0, -1, -1}) == "neither");  
    CHECK(detectTerrainType({9, 8, 9, 8}) == "neither");
}