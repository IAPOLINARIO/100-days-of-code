/**
 * DAY-70 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <fstream> //for file operation

/**
 * What is the longest valid English language word you can make for each keyboard configuration?
 * Uses "../../../../assets/dictionary1.txt"
 * 
 * @param wkeys Keyboard configuration
 * @return longest valid word from the dictonary1.txt
 */ 
std::string longestWord(std::string wkeys) {
    const std::string DICTIONARY_FILE = "../../../../assets/dictionary1.txt";
    const char NEW_LINE = '\n';
    const std::string EMPTY_RESULT = "";

    std::ifstream file(DICTIONARY_FILE, std::ifstream::in); //file open for reading
    if (!file) {                
        return EMPTY_RESULT;
    }        

    std::string selectedWord;
    std::string word;
    while (std::getline(file, word, NEW_LINE)) { //read the file, line by line        
        bool found;
        for (size_t i = 0; i < word.size(); i++) {
            found = false;
            char w = word[i];                     
            for (size_t j = 0; j < wkeys.size(); j++) {
                if (w == wkeys[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        if (found && word.size() > selectedWord.size()) {
            selectedWord = word;
        }
    }
    return selectedWord;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(longestWord("abcd") == "abaca");
    CHECK(longestWord("edcf") == "deeded");
    CHECK(longestWord("bnik") == "bikini");
    CHECK(longestWord("poil") == "lollipop");
    CHECK(longestWord("vybu") == "bubby");
    CHECK(longestWord("subtoxymerhlac") == "carboxymethylcelluloses");    
}


