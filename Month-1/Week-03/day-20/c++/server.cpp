/**
 * DAY-20 C++ version
 * Server implementation file
 * 
 * Just run 'make' to compile, turn the SERVER ON, run all the tests and shutdown the SERVER
 */

#define API_KEY "MY_SECRET_API_KEY" //Set the SECRET API KEY

#define CPPHTTPLIB_OPENSSL_SUPPORT //SSL support is available with CPPHTTPLIB_OPENSSL_SUPPORT. libssl and libcrypto should be linked
#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib (for server support, it also needs to be linked with libpthread)

#include "../../../../dependencies/c++/json.hpp" //https://github.com/nlohmann/json

/**
 * Call the Google Maps API
 * @param q search string
 * @param latitude Optional latitude for search
 * @param longitude Optional longitude for search
 * @return name, latitude, longitude and score of results in a 'suggestions' array JSON
 */ 
std::string callMapsAPI(std::string q, float latitude = 0, float longitude = 0) {
    const std::string SERVER = "maps.googleapis.com";
    const int HTTP_RESPONSE_OK = 200;
    
    std::string GET_REQUEST = "/maps/api/place/textsearch/json?query=" + q + "&key=" + API_KEY;

    if (latitude != 0 || longitude != 0) {
        GET_REQUEST += "&location=" + std::to_string(latitude) + "," + std::to_string(longitude) + "&radius=50000";
    }         

    httplib::SSLClient cli(SERVER);
    auto res = cli.Get(GET_REQUEST.c_str());
        
    if (res->status != HTTP_RESPONSE_OK) {
        nlohmann::json jsonErrorResponse;
        jsonErrorResponse["STATUS"] = res->status;
        jsonErrorResponse["MESSAGE"] = res->body;
        return jsonErrorResponse.dump();        
    }

    nlohmann::json jsonResponse = nlohmann::json::parse(res->body);      
    int countScore = 0;
    nlohmann::json output;    
    for (auto& e : jsonResponse["results"]) {
        nlohmann::json item;
        item["name"] = e["name"];
        item["latitude"] = e["geometry"]["location"]["lat"];
        item["longitude"] = e["geometry"]["location"]["lng"];
        item["score"] = static_cast<float>(1) / ++countScore;
        
        output["suggestions"].push_back(item);                
    }
    
    if (output["suggestions"].size() == 0) {
        output["suggestions"] = nlohmann::json::parse("[]");
    }

    return output.dump();
}

/**
 * Setup a local Web Server and start listening at port 1234 to serve endpoint GET /suggestions.
 * It also supports the '/stop' endpoint to shutdown the server.
 * The content is served as application/json.
 */ 
void setupServer(void) {    
    httplib::Server server;

    server.Get("/suggestions", [&](const httplib::Request& req, httplib::Response& res) {        
        std::string q = req.has_param("q") ? req.get_param_value("q") : " ";        
        float latitude = req.has_param("latitude") ? std::stof(req.get_param_value("latitude")) : 0;
        float longitude = req.has_param("longitude") ? std::stof(req.get_param_value("longitude")) : 0;        
                
        std::string content = callMapsAPI(q, latitude, longitude);
        res.set_content(content, "application/json");
    });

    server.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {        
        std::cout << "\nServer received /stop http request.\nShutting down..." << std::endl;
        server.stop();    
    });

    server.listen("localhost", 1234);    
}

/**
 * Entry point of application.
 * Starts the server.
 */ 
int main(int argc, char *argv[]) { 
    setupServer();
}