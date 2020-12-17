/**
 * DAY-20 C++ version
 * Main test program file
 * It assumes a server @localhost:1234 is up and running.
 * 
 * Just run 'make' to compile, turn the SERVER ON, run all the tests and shutdown the SERVER.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib

#include "../../../../dependencies/c++/json.hpp" //https://github.com/nlohmann/json

/**
 * Call the GET '/suggestions' API, served at localhost, port 1234.
 * It uses the Google Maps API internally to build part of the results.
 * 
 * @param q search string 
 * @param latitude Optional latitude for search
 * @param longitude Optional longitude for search
 * @return name, latitude, longitude and score of results in a 'suggestions' array JSON  
 */ 
std::string callSuggestionsAPI(std::string q, float latitude = 0, float longitude = 0) {
    const int HTTP_RESPONSE_OK = 200;
    const std::string SERVER = "http://localhost:1234";
    std::string GET_REQUEST = "/suggestions?q=" + q + "&latitude=" + std::to_string(latitude) + "&longitude=" + std::to_string(longitude);
    
    httplib::Client cli(SERVER.c_str());
    auto res = cli.Get(GET_REQUEST.c_str());
    
    if (res->status != HTTP_RESPONSE_OK) {
        nlohmann::json jsonErrorResponse;
        jsonErrorResponse["STATUS"] = res->status;
        jsonErrorResponse["MESSAGE"] = res->body;
        return jsonErrorResponse.dump();        
    }

    nlohmann::json jsonResponse = nlohmann::json::parse(res->body);
    return jsonResponse.dump();
}

/**
 * Call the /stop API endpoint on the localserver to shutdown it. 
 */
bool callServerOff(void) {       
    const std::string SERVER = "http://localhost:1234";
    httplib::Client cli(SERVER.c_str());
    auto res = cli.Get("/stop");
    return true;
}


/**
 * Tests
 */
TEST_CASE("Tests") //Assuming server is up by calling the Makefile...
{                                  
    CHECK(callSuggestionsAPI("xxxxxxxxxxxxxxxxxxxxxxxxxx") == "{\"suggestions\":[]}"); //Empty result    
    CHECK(nlohmann::json::parse(callSuggestionsAPI("Lond"))["suggestions"].size() == 2); //London & Londrina

    //Call the API with a search string and parse json results
    auto j = nlohmann::json::parse(callSuggestionsAPI("Bodytech - Shopping Iguatemi"));   

    CHECK(j["suggestions"].size() == 1); //There is only one "Bodytech - Shopping Iguatemi"
    CHECK(j["suggestions"][0]["name"] == "Bodytech - Shopping Iguatemi"); //Check exact name "Bodytech - Shopping Iguatemi"
    CHECK(j["suggestions"][0]["latitude"] == -23.5765562); //Check exact latitude of "Bodytech - Shopping Iguatemi"
    CHECK(j["suggestions"][0]["longitude"] == -46.6878809); //Check exact longitude of "Bodytech - Shopping Iguatemi"
    CHECK(j["suggestions"][0]["score"] == 1); //Check score -> 1 (high confidence)

    CHECK(callServerOff() == true); //shutdown server
}