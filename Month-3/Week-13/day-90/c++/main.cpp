/**
 * DAY-90 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <algorithm> 
#include <functional> //function as arguments

/**
 * Generate Nginx configuration with documentation.
 * @param numberOfServers Number of servers
 * @param numberOfCommands Number of commands
 * @param serversData Server data (name and ip address)
 * @param commandsData Commands data (commands for each ip)
 * @return Nginx config
 */ 
std::string nginxConfig(const int numberOfServers, const int numberOfCommands, const std::vector<std::string> serversData, const std::vector<std::string> commandsData) {
    const std::string INVALID_NGINX_CONFIG = "#INVALID_NGINX_CONFIG";
    const std::string NO_SERVER_NAME_AVAILABLE = "SERVER NAME ???"; //only IP available
    
    if (numberOfServers <= 0 || numberOfCommands <= 0 || numberOfServers != serversData.size() || numberOfCommands != commandsData.size()) {
        return INVALID_NGINX_CONFIG; //invalid nginx config!
    }

    //mapping of servers, ips and commands
    std::map<std::string, std::string> servers;     
    std::vector<std::pair<std::string, std::string>> commands;
    
    //helper lambda just to garantee a cleaner content, without spaces
    const auto cleaner = [&](std::string &s) { s.erase(std::remove(s.begin(), s.end(), ' '), s.end()); };

    //helper lambda to build data mapping of servers, ips and commands
    const auto build = [&](const std::vector<std::string> &data, const std::function<bool (std::string, std::string)> &mapper) {        
        bool r = true;
        for (auto &d : data) {
            std::string name = d.substr(0, d.find(' '));
            std::string ip = d.substr(d.find(' ') + 1, d.size() - 1);            
            cleaner(name); 
            cleaner(ip);
            if (name.empty() || ip.empty() || !mapper(name, ip)) {                                           
                return false;
            }            
        }
        return r;
    };

    //helper lambda specialized in mapping servers
    const auto serversMapper = [&servers](const std::string name, const std::string ip) { 
        servers[ip] = name;
        return true;
    };

    //helper lambda specialized in mapping commands
    const auto commandsMapper = [&commands](const std::string name, const std::string ip) {         
        if (ip.back() != ';') {
            return false; //each Nginx commmand needs to finish with ';'!
        }
        commands.push_back(std::make_pair(name, ip.substr(0, ip.size() - 1)));        
        return true;
    };
        
    //build the mappings and check for invalid Nginx config
    if (!build(serversData, serversMapper) || !build(commandsData, commandsMapper)) {
        return INVALID_NGINX_CONFIG;
    }
    
    //output Nginx config
    std::string r;
    for (auto &c : commands) {
        r += c.first + " " + c.second + "; #" + (servers.find(c.second) != servers.end() ? servers[c.second] : NO_SERVER_NAME_AVAILABLE) + '\n';
    }

    return r;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(nginxConfig(2, 2, {"main 192.168.0.2", 
                            "replica 192.168.0.1"}, {"block 192.168.0.1;", 
                                                     "proxy 192.168.0.2;"}) ==
R"(block 192.168.0.1; #replica
proxy 192.168.0.2; #main
)");

    CHECK(nginxConfig(3, 5, {"google 8.8.8.8", 
                            "codeforces 212.193.33.27",
                            "server 138.197.64.57"}, {"redirect 138.197.64.57;", 
                                                     "block 8.8.8.8;",
                                                     "cf 212.193.33.27;",
                                                     "unblock 8.8.8.8;",
                                                     "check 138.197.64.57;"}) ==
R"(redirect 138.197.64.57; #server
block 8.8.8.8; #google
cf 212.193.33.27; #codeforces
unblock 8.8.8.8; #google
check 138.197.64.57; #server
)");
}











