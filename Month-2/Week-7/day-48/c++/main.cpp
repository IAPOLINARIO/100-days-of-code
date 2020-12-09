/**
 * DAY-48 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include "../../../../dependencies/c++/color.hpp" //https://github.com/fengwang/colorize

/**
 * Create a Christmas tree based on height.
 * @param h Height
 * @return Christmas tree
 */ 
std::string tree(int h) {
    const std::string GREEN = "Light Green";
    const std::string RED = "Light Red";

    std::string tree;
    int width = h * 2 - 1;
    for (int i = 0; i < h; i++) {
        int x = width / 2 - i;
        std::string segment;
        for (int j = 0; j < width; j++) {            
            segment += (j < x || j >= (width - x)) ? ' ' : '#';
        }
        std::cout << color::rize(segment, i == 0 ? RED : GREEN) << '\n'; //optional print the tree segment in colors
        tree += segment + '\n';        
    }    

    return tree;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(tree(3) == 
R"(  #  
 ### 
#####
)");

    CHECK(tree(12) == 
R"(           #           
          ###          
         #####         
        #######        
       #########       
      ###########      
     #############     
    ###############    
   #################   
  ###################  
 ##################### 
#######################
)");

}