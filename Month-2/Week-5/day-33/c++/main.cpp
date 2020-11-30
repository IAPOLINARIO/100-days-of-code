/**
 * DAY-33 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Print the correct string from an input full of common typing errors.
 * @param input The input with typing errors
 * @return the message decoded
 */ 
std::string keyboardMistakeFix(std::string input) {
    std::map<char, char> kb;

    //keys of the first line
    kb['1'] = '`';
    kb['2'] = '1';
    kb['3'] = '2';
    kb['4'] = '3';
    kb['5'] = '4';
    kb['6'] = '5';
    kb['7'] = '6';
    kb['8'] = '7';
    kb['9'] = '8';
    kb['0'] = '9';
    kb['-'] = '0';
    kb['='] = '-';

    //keys of the second line
    kb['w'] = 'q';
    kb['e'] = 'w';
    kb['r'] = 'e';
    kb['t'] = 'r';
    kb['y'] = 't';
    kb['u'] = 'y';
    kb['i'] = 'u';
    kb['o'] = 'i';
    kb['p'] = 'o';
    kb['['] = 'p';
    kb[']'] = '[';
    kb['\\'] = ']';

    //keys of the third line
    kb['s'] = 'a';
    kb['d'] = 's';
    kb['f'] = 'd';
    kb['g'] = 'f';
    kb['h'] = 'g';
    kb['j'] = 'h';
    kb['k'] = 'j';
    kb['l'] = 'k';
    kb[';'] = 'l';
    kb['\''] = ';';
    
    //keys of the fourth line
    kb['x'] = 'z';
    kb['c'] = 'x';
    kb['v'] = 'c';
    kb['b'] = 'v';
    kb['n'] = 'b';
    kb['m'] = 'n';
    kb[','] = 'm';
    kb['.'] = ',';
    kb['/'] = '.';
    
    std::string r;
    for (int i = 0; i < input.size(); i++) {
        char code = tolower(input[i]);
        auto it = kb.find(code);
        r += (it != kb.end()) ? toupper(kb[code]) : input[i];
    }
    
    return r;
 }

/**
 * Tests
 */
TEST_CASE("Tests")
{           
    CHECK(keyboardMistakeFix("O S, GOMR YPFSU/") == "I AM FINE TODAY.");
    CHECK(keyboardMistakeFix("JPKR DO,. JPKR MAP") == "HOJE SIM, HOJE NAO");
    CHECK(keyboardMistakeFix("YTO[;RC") == "TRIPLEX");
}