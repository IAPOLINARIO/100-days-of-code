/**
 * DAY-02 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <sstream>  //std::istringstream

std::string findNemo(std::string s) {
   int position = 0;   
   std::string token;
   std::istringstream tokenStream(s);   
   while (std::getline(tokenStream, token, ' ')) //tokenize string s
   {
      if (token.compare("Nemo") == 0) { //find Nemo          
          return "I found Nemo at " + std::to_string(++position) + "!";
      }      
      position++;
   }       
   return "I can't find Nemo :(";
}

/**
 * Finding Nemo TEST
 */
TEST_CASE("Finding Nemo TEST") {    

    CHECK(findNemo("I am finding Nemo !") == "I found Nemo at 4!");
    CHECK(findNemo("Nemo is me") == "I found Nemo at 1!");
    CHECK(findNemo("I Nemo am") == "I found Nemo at 2!");    
    CHECK(findNemo("I Neno am") == "I can't find Nemo :(");    
}