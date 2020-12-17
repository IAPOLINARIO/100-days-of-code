/**
 * DAY-35 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <fstream> //for file operation


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/**
 * Represents a Escape Plan
 */ 
struct EscapePlan {
        int numberOfHoles;
        std::pair<double, double> gopherPos; //position of gopher
        std::pair<double, double> dogPos; //position of dog
        std::vector<std::pair<double, double>> holes; //list of hole positions
};

/**
 * Based on a Escape Plan, save a GOOD or BAD ending for the gopher.
 * @param escapePlan The structure of whe escape plan, considering the positions of the animals and the holes in the field
 * @param r The output list to save results
 */ 
void processEscapePlan(EscapePlan &escapePlan, std::vector<std::string> &r) {    
    const double GOPHER_SPEED = 1.0;
    const double DOG_SPEED = 2 * GOPHER_SPEED;
    const std::string BAD_ENDING = "The gopher cannot escape.";
    const std::string GOOD_ENDING = "The gopher can escape through the hole at";
        
    for (int i = 0; i < escapePlan.holes.size(); i++) {
        double gopherDistanceToHole = sqrt( pow(abs(escapePlan.holes[i].first - escapePlan.gopherPos.first), 2.0) +  pow(abs(escapePlan.holes[i].second - escapePlan.gopherPos.second), 2.0) );
        double dogDistanceToHole = sqrt( pow(abs(escapePlan.holes[i].first - escapePlan.dogPos.first), 2.0) +  pow(abs(escapePlan.holes[i].second - escapePlan.dogPos.second), 2.0) );

        double gopherTimeToHole = gopherDistanceToHole / GOPHER_SPEED;
        double dogTimeToHole = dogDistanceToHole / DOG_SPEED;

        if (gopherTimeToHole < dogTimeToHole) {
            r.push_back(GOOD_ENDING + " (" + std::to_string(escapePlan.holes[i].first) + "," + std::to_string(escapePlan.holes[i].second) + ").");
            return; //"If the gopher can escape through more than one hole, report the one that appears first in the input."
        }
    }

    r.push_back(BAD_ENDING);    
}

/**
 * Manages the output for BAD FILE scenarios.
* @param r The output list to save results
 */ 
std::vector<std::string> badFile(std::vector<std::string> &r) {
    const std::string BAD_FILE = "BAD FILE!";
    r.clear();
    r.push_back(BAD_FILE);
    return r;
}


/**
 * The main function. Select a hole through which the gopher can escape, if such a hole exists, 
 * by reading a file with a variable set of scenarios.
 * @param filename The filename with escape plan scenarios
 * @param The output list to save results
 */ 
std::vector<std::string> gopherEscapePlan(std::string filename) {    
    const int NUMBER_OF_HOLES_INDEX = 0;
    const int GOPHER_POSITION_X_INDEX = 1;
    const int GOPHER_POSITION_Y_INDEX = 2;
    const int DOG_POSITION_X_INDEX = 3;
    const int DOG_POSITION_Y_INDEX = 4;
    const int HOLE_X_POSITION_INDEX = 0;
    const int HOLE_Y_POSITION_INDEX = 1;    
    const int ANIMALS_POSITIONS_MAX_FIELDS = 5;
    const int HOLES_POSITIONS_MAX_FIELDS = 2;
    const char NEW_LINE = '\n';

    std::vector<std::string> r;

    std::ifstream file(filename, std::ifstream::in); //file open for reading
    if (!file) {                
        return badFile(r);
    }        

    EscapePlan escapePlan;
    std::vector<EscapePlan> espacePlans;    
    bool newEscapePlanSet = true;
    bool startOfFile = true;
    std::string line; 

    while (std::getline(file, line, NEW_LINE)) { //read the file, line by line
        trim(line); //ignore whitespace in the line

        //ignore empty lines at the beginning of the file or between complete sets (still a valida file)
        if ((startOfFile || newEscapePlanSet) && line.size() == 0 ) {
            continue;
        }

        if (!startOfFile && line.size() == 0) {
            //validation of the plan
            if (!newEscapePlanSet && (escapePlan.holes.size() == 0 || escapePlan.holes.size() != escapePlan.numberOfHoles)) {
                return badFile(r);
            }            
            newEscapePlanSet = true;
            processEscapePlan(escapePlan, r);
            escapePlan = {};
            continue;
        }        

        startOfFile = false;                

        int index = 0;
        int numberOfHoles;        
        std::pair<double, double> holePosition;       
        
        std::istringstream iss(line);
        std::string value;
        while (std::getline(iss, value, ' ')) { //tokenize the line and populate the fields of the escape plan
            if (newEscapePlanSet) {
                switch (index++)
                {
                case NUMBER_OF_HOLES_INDEX:
                    escapePlan.numberOfHoles = std::stoi(value);
                    break;                
                case GOPHER_POSITION_X_INDEX:
                    escapePlan.gopherPos.first = std::stof(value);
                    break;
                case GOPHER_POSITION_Y_INDEX:
                    escapePlan.gopherPos.second = std::stof(value);
                    break;
                case DOG_POSITION_X_INDEX:
                    escapePlan.dogPos.first = std::stof(value);
                    break;                
                case DOG_POSITION_Y_INDEX:
                    escapePlan.dogPos.second = std::stof(value);
                    break;                  
                }
            } else {
                 switch (index++)
                {
                case HOLE_X_POSITION_INDEX:
                    holePosition.first = std::stof(value);
                    break;                
                case HOLE_Y_POSITION_INDEX:
                    holePosition.second = std::stof(value);
                    break;                
                }
            }              
        }        

        if ((newEscapePlanSet && index != ANIMALS_POSITIONS_MAX_FIELDS) || (!newEscapePlanSet && index != HOLES_POSITIONS_MAX_FIELDS)) {            
            return badFile(r);
        }
        
        if (!newEscapePlanSet) {
            escapePlan.holes.push_back(holePosition);
        }

        newEscapePlanSet = false;        
    }

    //validation of the plan
    if (!newEscapePlanSet && (escapePlan.holes.size() == 0 || escapePlan.holes.size() != escapePlan.numberOfHoles)) {
        return badFile(r);
    }

    if (!newEscapePlanSet) {
        processEscapePlan(escapePlan, r);
    }
    
    return r;
}


/**
 * Tests
 */
TEST_CASE("Tests")
{           
   CHECK(gopherEscapePlan("../../../../assets/day-35_sample_1_valid.txt") == std::vector<std::string>{"The gopher cannot escape.", "The gopher can escape through the hole at (2.500000,2.500000)."});
   CHECK(gopherEscapePlan("../../../../assets/day-35_sample_2_valid.txt") == std::vector<std::string>{"The gopher cannot escape.", "The gopher can escape through the hole at (2.500000,2.500000)."});
   CHECK(gopherEscapePlan("../../../../assets/day-35_sample_3_invalid.txt") == std::vector<std::string>{"BAD FILE!"});
   CHECK(gopherEscapePlan("../../../../assets/day-35_sample_4_invalid.txt") == std::vector<std::string>{"BAD FILE!"});
   CHECK(gopherEscapePlan("../../../../assets/day-35_sample_5_invalid.txt") == std::vector<std::string>{"BAD FILE!"});
}