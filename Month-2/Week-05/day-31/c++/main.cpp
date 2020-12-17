/**
 * DAY-31 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Given the time in numerals we may convert it into words.
 * @param h Hour (1 - 12)
 * @param m Minute (0 - 59)
 * @return Description of time
 */ 
std::string timeInWords(int h, int m) {
    //Declare an internal class HOUR_OF_THE_DAY with just one public static method DESCRIPTION
    class HOUR_OF_THE_DAY {                                          
        public:
            static const std::string DESCRIPTION(int h, int m)  {
                const std::string SPACE = " ";            
                const int TO_LIMIT = 30; 
                const int REMAINING_LIMIT = 60;  
                
                const std::map<int, std::string> hMap  = {
                    {1, "one"},
                    {2, "two"},
                    {3, "three"},
                    {4, "four"},
                    {5, "five"},
                    {6, "six"},
                    {7, "seven"},
                    {8, "eight"},
                    {9, "nine"},
                    {10, "ten"},
                    {11, "eleven"},
                    {12, "twelve"}
                };

                const std::map<int, std::string> mMap = {
                    {0, "o' clock"},
                    {1, "one minute"},
                    {2, "two minutes"},
                    {3, "three minutes"},
                    {4, "four minutes"},
                    {5, "five minutes"},
                    {6, "six minutes"},
                    {7, "seven minutes"},
                    {8, "eight minutes"},
                    {9, "nine minutes"},
                    {10, "ten minutes"}, 
                    {11, "eleven minutes"},
                    {12, "twelve minutes"},
                    {13, "thirteen minutes"},
                    {14, "fourteen minutes"},
                    {15, "quarter"},
                    {16, "sixteen minutes"},
                    {17, "seventeen minutes"},
                    {18, "eighteen minutes"},
                    {19, "nineteen minutes"},
                    {20, "twenty minutes"},
                    {21, "twenty one minutes"},
                    {22, "twenty two minutes"},
                    {23, "twenty three minutes"},
                    {24, "twenty four minutes"},
                    {25, "twenty five minutes"},
                    {26, "twenty six minutes"},
                    {27, "twenty seven minutes"},
                    {28, "twenty eight minutes"},
                    {29, "twenty nine minutes"},
                    {30, "half"}
                };

                const std::map<bool, std::string> pMap = {                
                    {true, "past"},
                    {false, "to"}
                };                

                return  m == 0 ? hMap.at(h) + SPACE + mMap.at(m) : mMap.at(m < TO_LIMIT ? m : REMAINING_LIMIT - m) + SPACE + pMap.at(m <= TO_LIMIT) + SPACE + hMap.at(m <= TO_LIMIT ? h % hMap.size() : (h + 1) % hMap.size());
        }
    };
        
    return HOUR_OF_THE_DAY::DESCRIPTION(h, m); //use static method of the local class
}

/**
 * Tests
 */
TEST_CASE("Tests") //Constraints defined: 1 <= h <= 12 and 0 <= m < 60
{    
    CHECK(timeInWords(5, 0) == "five o' clock");
    CHECK(timeInWords(5, 1) == "one minute past five");
    CHECK(timeInWords(5, 10) == "ten minutes past five");
    CHECK(timeInWords(5, 15) == "quarter past five");
    CHECK(timeInWords(5, 28) == "twenty eight minutes past five");
    CHECK(timeInWords(5, 30) == "half past five");
    CHECK(timeInWords(5, 40) == "twenty minutes to six");
    CHECK(timeInWords(5, 45) == "quarter to six");
    CHECK(timeInWords(5, 47) == "thirteen minutes to six");
    CHECK(timeInWords(12, 40) == "twenty minutes to one");
    CHECK(timeInWords(12, 59) == "one minute to one");
}
