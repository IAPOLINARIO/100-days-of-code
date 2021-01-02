/**
 * DAY-96 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 *  
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * What is the maximum possible number of times the visitor may become happy while passing all pictures from first to last? 
 * 
 * @param paintings The paintings
 * @reutrn Number of times the visitor may become happy
 */ 
int beautifulPaints(std::vector<int> paintings) {
    if (paintings.empty()) {
        return 0; //invalid constraint
    }

    std::sort(paintings.begin(), paintings.end());
    int lastPaint = paintings[0];
    int r = 0;
    for (size_t i = 1; i < paintings.size(); i++) {
        bool found = paintings[i] > lastPaint;
        if (!found) {           
            for (size_t j = i; j < paintings.size() && !found; j++) {
                if (paintings[j] > lastPaint) {                    
                    lastPaint = paintings[j];
                    found = true;
                    r++;                    
                }
            }
        } 
        if (!found) {
            lastPaint = paintings[i];
        } else {
            r++;
        }
    }

    return r;

}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(beautifulPaints({20, 30, 10, 50, 40}) == 4);
    CHECK(beautifulPaints({200, 100, 100, 200}) == 2);
}











