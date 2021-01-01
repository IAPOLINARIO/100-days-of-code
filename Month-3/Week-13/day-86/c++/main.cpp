/**
 * DAY-86 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Abbreviate words larger than 10 characteres.
 * @param word Original word
 * @return Abbreviated word
 */ 
std::string abbreviate(std::string word) {
    if (word.length() > 10) {
        word = word[0] + std::to_string(word.length() - 2) + word.back();
    }
    return word;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(abbreviate("word") == "word");
    CHECK(abbreviate("localization") == "l10n");
    CHECK(abbreviate("internationalization") == "i18n");
    CHECK(abbreviate("pneumonoultramicroscopicsilicovolcanoconiosis") == "p43s");
}