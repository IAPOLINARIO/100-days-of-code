/**
 * DAY-98 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#define CPPHTTPLIB_OPENSSL_SUPPORT //SSL support is available with CPPHTTPLIB_OPENSSL_SUPPORT. libssl and libcrypto should be linked
#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib (for server support, it also needs to be linked with libpthread)

#include "../../../../dependencies/c++/json.hpp" //https://github.com/nlohmann/json

/**
 * Get the number of municipalities in the state informed
 * @param stateAcronym The State's acronym
 * @return Number of municipalities
 */ 
int brazilMunicipalitiesNumber(const std::string stateAcronym) {
    const int ERROR = -1;        

    if (stateAcronym.empty()) {
        return ERROR; //invalid constraint
    }

    const int HTTP_RESPONSE_OK = 200;
    const std::string SERVER = "servicodados.ibge.gov.br";
    const std::string GET_REQUEST = "/api/v1/localidades/municipios";

    httplib::SSLClient cli(SERVER);
    auto res = cli.Get(GET_REQUEST.c_str());
    if (res->status != HTTP_RESPONSE_OK) {
        return ERROR;   
    }

    std::map<std::string, int> states;
    nlohmann::json jsonResponse = nlohmann::json::parse(res->body);     
    for (auto& city: jsonResponse) {
        const std::string state = city["microrregiao"]["mesorregiao"]["UF"]["sigla"];
        states[state] += 1;
    }

    return states.at(stateAcronym);
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(brazilMunicipalitiesNumber("SP") == 645);
    CHECK(brazilMunicipalitiesNumber("RJ") == 92);
}