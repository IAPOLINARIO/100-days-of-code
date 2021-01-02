/**
 * DAY-99 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#define CPPHTTPLIB_OPENSSL_SUPPORT //SSL support is available with CPPHTTPLIB_OPENSSL_SUPPORT. libssl and libcrypto should be linked
#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib (for server support, it also needs to be linked with libpthread)

#include "../../../../dependencies/c++/json.hpp" //https://github.com/nlohmann/json

#include <regex>
#include <tuple>

/* structure to store the weather forecast */
struct WeatherForecast {
    std::string city;
    std::string state;
    std::vector<std::tuple<std::tuple<int, int, std::string>, std::tuple<int, int, std::string>, std::tuple<int, int, std::string>>> days;    
};

/**
 * Common function for httpRequests.
 * @param server Server to connect
 * @param request API request
 * @return JSON response (empty for bad result)
 */ 
nlohmann::json getHttpResponse(const std::string server, const std::string request) {
    const int ERROR = -1;        
    const int HTTP_RESPONSE_OK = 200;
    
    const std::string SERVER = server;
    const std::string GET_REQUEST = request;

    httplib::SSLClient cli(SERVER);
    auto res = cli.Get(GET_REQUEST.c_str());

    nlohmann::json r; 
    if (res->status == HTTP_RESPONSE_OK) {
        r = nlohmann::json::parse(res->body);
    }

    return r;
}

/**
 * Build the map of all municipalities of Brazil
 * @return Map with a std::pair with name, state and internal IBGE id
 */ 
std::map<std::pair<std::string, std::string>, int> buildMunicipalitiesOfBrazil() {
    std::map<std::pair<std::string, std::string>, int> cities;

    nlohmann::json jsonResponse =  getHttpResponse("servicodados.ibge.gov.br", "/api/v1/localidades/municipios");
    for (auto& city: jsonResponse) {
        const std::string name = city["nome"];
        const std::string state = city["microrregiao"]["mesorregiao"]["UF"]["sigla"];        
        const int id = city["id"];
        cities[std::make_pair(name, state)] = id;
    }

    return cities;
}

/**
 * The main function, get the Weather Forecast
 * @param cityName Name of the city (can be partial name)
 * @param stateAcronym State acronym (2 character long)
 * @return Weather Forecast
 */ 
WeatherForecast getWeatherForecast(std::string cityName, std::string stateAcronym) {
    WeatherForecast w;    

    //check parameters
    if (cityName.empty() || stateAcronym.size() != 2 || islower(stateAcronym[0]) || islower(stateAcronym[1])) {
        std::cout << "Invalid parameter(s)" << std::endl;
        return w;
    }

    //build the map of the cities
    auto cities = buildMunicipalitiesOfBrazil();
    if (cities.empty()) {
        std::cout << "Error loading cities!" << std::endl;
        return w;
    }

    //prepare a regex search for the name of the city in parameter
    std::smatch m;
    std::regex e("\\b(" + cityName + ")([^ ]*)", std::regex::icase); //ignore case, matches names beginning with 'cityName'
    
    //try to get the city ID (necessary for the weather API)
    int cityId = -1;
    for (auto &city : cities) {
        if (city.first.second == stateAcronym) {
            if (std::regex_search(city.first.first, m, e)) {
                w.city = city.first.first;
                w.state = stateAcronym;

                cityId = cities[city.first];
                break;
            }
        }
    }

    //city not found
    if (cityId == -1) {
        std::cout << "City " << cityName << "not found!" << std::endl;
        return w;
    }
    
    //call the Weather API from IBGE
    nlohmann::json jsonResponse =  getHttpResponse("apiprevmet3.inmet.gov.br", "/previsao/" + std::to_string(cityId));    
    if (jsonResponse.empty()) {
        std::cout << "Error loading Weather Forecast!" << std::endl;
        return w;
    }
   
    //Process response and build the return object
    for (auto& weatherData: jsonResponse) {    
        for (auto& weatherDataOfDay: weatherData) {    
            std::tuple<std::tuple<int, int, std::string>, std::tuple<int, int, std::string>, std::tuple<int, int, std::string>> forecastOfDay;
            const bool hasMultipleForecastsForTheDay = weatherDataOfDay.size() == 3;            
            if (hasMultipleForecastsForTheDay) {
                std::tuple<int, int, std::string> morning = std::make_tuple(weatherDataOfDay["manha"]["temp_min"], weatherDataOfDay["manha"]["temp_max"], weatherDataOfDay["manha"]["resumo"]); //forecast(hasMultipleForecastsForTheDay, weatherDataOfDay, "manha");
                std::tuple<int, int, std::string> afternoon = std::make_tuple(weatherDataOfDay["tarde"]["temp_min"], weatherDataOfDay["tarde"]["temp_max"], weatherDataOfDay["tarde"]["resumo"]);
                std::tuple<int, int, std::string> evening = std::make_tuple(weatherDataOfDay["noite"]["temp_min"], weatherDataOfDay["noite"]["temp_max"], weatherDataOfDay["noite"]["resumo"]);
                forecastOfDay = std::make_tuple(morning, afternoon, evening);
            } else {
                std::tuple<int, int, std::string> allday = std::make_tuple(weatherDataOfDay["temp_min"], weatherDataOfDay["temp_max"], weatherDataOfDay["resumo"]);
                forecastOfDay = std::make_tuple(allday, allday, allday);
            }
            w.days.push_back(forecastOfDay);            
        }
    }

    return w;    
}

/**
 * Tests
 */
TEST_CASE("Tests")
{   
    auto r = getWeatherForecast("Campin", "SP");
    CHECK(r.state == "SP");
    CHECK(r.city == "Campina do Monte Alegre");
    CHECK(!r.days.empty());
    
    r = getWeatherForecast("Campinas", "SP");
    CHECK(r.state == "SP");
    CHECK(r.city == "Campinas");
    CHECK(!r.days.empty());
}