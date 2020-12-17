/**
 * DAY-61 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#define CPPHTTPLIB_OPENSSL_SUPPORT //SSL support is available with CPPHTTPLIB_OPENSSL_SUPPORT. libssl and libcrypto should be linked
#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib (for server support, it also needs to be linked with libpthread)
#include <queue>

/**
 * Get the host from an URL
 * @param url URL
 * @return Host
 */ 
static std::string getHostFromUrl(const std::string &url) {
  static const std::regex urlRe("^.*://([^/?:]+)/?.*$");
  return std::regex_replace(url, urlRe, "$1");
}

/**
 * Extract links from content of a page and updates the Discovery List and returns the newly found URLs on a queue
 * @param content Content from a page
 * @param discoveredURLs Control of already discovered URLs
 * @return Queue of the new URLs that may be visited (depends on depth level)
 */ 
std::queue<std::string> extractLinksAndUpdateDiscovery(const std::string content, std::vector<std::string>  &discoveredURLs) {
    static const std::regex hl_regex( "<a href=\"(.*?)\">", std::regex_constants::icase);    
    std::set<std::string> extracted = {std::sregex_token_iterator(content.begin(), content.end(), hl_regex, 1), std::sregex_token_iterator{}};
    std::queue<std::string> newDepthVisitQueue;
    for (auto &e : extracted) {        
        discoveredURLs.push_back(e);
        newDepthVisitQueue.push(e);        
    }
    return newDepthVisitQueue;
}

/**
 * Visits all the URLs of a queue.
 * @param visitQueue Queue of URLs to visit
 * @param discoveredURLs Control of already discovered URLs
 * @param maxDepth Max depth allowed to visit
 * @param depth Current depth level
 */ 
void go(std::queue<std::string> &visitQueue, std::vector<std::string>  &discoveredURLs, const int maxDepth, int depth = 1) {
    std::queue<std::string>  newURLsToVisit;
    
    while (!visitQueue.empty()) {                   
        const auto url = visitQueue.front();
        visitQueue.pop(); //remove from queue            
        const int HTTP_RESPONSE_OK = 200;                
        const std::string serverName = getHostFromUrl(url);
        const std::string pathName = url.substr(url.find(serverName) + serverName.size(), std::string::npos);            
        httplib::SSLClient cli(serverName.c_str());
        cli.set_follow_location(true); //follow redirects (301)   
        
        if (auto res = cli.Get(pathName.empty() ? "/" : pathName.c_str())) {                               
            if (res->status == HTTP_RESPONSE_OK) {                             
                //extract all the URLs from current page and update the list of discovered URLs                                                
                newURLsToVisit = extractLinksAndUpdateDiscovery(res->body, discoveredURLs);                    
            } 
        }                
    }   
    
    //check the depth limit
    if (++depth <= maxDepth) {
        //go visit the new URLs and repeat the process
        go(newURLsToVisit, discoveredURLs, maxDepth, depth);
    }
}

/**
 * A simple, single threaded Web Crawler.
 * @param seedURL A starting (seed) URL 
 * @param maxDepth Maximum depth to recurse to
 * @return Discovered URLs
 */ 
std::vector<std::string> crawler(const std::string seedURL, const int maxDepth) {
    std::vector<std::string> discoveredURLs;
    std::queue<std::string> visitQueue;
    visitQueue.push(seedURL);
    discoveredURLs.push_back(seedURL);
    go(visitQueue, discoveredURLs, maxDepth);
    return discoveredURLs;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    std::vector<std::string> r;

    r = crawler("www.globo.com", 1);
    CHECK(r.size() > 100); //there are more than 100 URL links just on the first level of depth on www.globo.com
    
    r = crawler("www.uol.com", 1);
    CHECK(r.size() > 100); //there are more than 100 URL links just on the first level of depth on www.uol.com
}


