/**
 * DAY-54 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <regex>

/**
 * Converts color in RGB format to Hex format.
 * @param rgb The RGB format ("rgb(color1, color2, color3)")
 * @return Hex color format 
 */ 
std::string rgbToHex(std::string rgb) {                
    std::string hex = "#";
    
    std::regex regexRGB("(rgb\\(\\s*(\\s*[0-9]{1,3})\\s*,\\s*([0-9]{1,3})\\s*,\\s*([0-9]{1,3}\\s*)*)");
    std::smatch matches;        

    if(std::regex_search(rgb, matches, regexRGB)) {        
        for (size_t i = 2; i < 5 && i < matches.size(); ++i) {                                
            std::stringstream ssHex;
            ssHex << std::setw(2) << std::setfill('0') << std::hex << atoi(matches[i].str().c_str());
            hex += ssHex.str();        
        }
    } 
    
    return hex;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(rgbToHex("rgb(0, 128, 192)") == "#0080c0");

    //testing different character spaces
    CHECK(rgbToHex("rgb(   45, 255,    192)") == "#2dffc0");

    CHECK(rgbToHex("rgb(0, 0, 0)") == "#000000");

    //invalid RGB color input format
    CHECK(rgbToHex("(10, 10, 10)") == "#");
}

