/**
 * DAY-19 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <regex>

/* Mock object representing an EXTERNAL DATABASE responsable to store data and generate sequence IDs */
std::vector<std::string> EXTERNAL_DATABASE;
const unsigned int SEQUENCE_OFFSET = 1000000;

/**
 * Default message for invalid URLs, used in many scenarios.
 * @return message of invalid URL
 */
std::string invalidURLMessage(void) {
    return "INVALID URL";    
}

/**
 * Save the URL provided by the user into the 'database' and return a sequence ID.
 * @param url URL to save
 * @param db the database
 * @return generated sequence of save
 */
int save(std::string url, std::vector<std::string> &db) {    
    db.push_back(url);
    return db.size() + SEQUENCE_OFFSET;
}

/**
 * Get the URL provided by a decoded sequence ID.
 * @param id the decoded sequence ID
 * @param db the database
 * @return generated sequence of save
 */
std::string get(int id, std::vector<std::string> &db) {
    const int value = id - 1 - SEQUENCE_OFFSET;
    if (value >= db.size()) {
        return invalidURLMessage();
    } else {
        return db[id - 1 - SEQUENCE_OFFSET];
    }    
}

/**
 * The encode Base System
 */
std::vector<char> getBase(void) {
    return     {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
}

/**
 * Encode an id to a new base system.
 * @param id - the id to encode
 * @param base - the encode base system
 * @return part of the encoded URL string
 */
std::string encode(int id, std::vector<char> base) {
    std::vector<int> newBaseIndex;
    while (id > 0) {        
        int mod = id % base.size();        
        newBaseIndex.push_back(mod);
        id = id / base.size();                
    }    

    std::string r;
    for (int i = newBaseIndex.size() - 1; i >= 0; i--) {        
        r += base[newBaseIndex[i]];
    }
    return r;
}

/**
 * Decode part of an encoded short URL to an numerical ID
 * @param id - the id to encode
 * @param base - the encode base system to use to decode
 * @return the calculated ID of the provided encoded URL
 */
int decode(std::string code, std::vector<char> base) {        
    code = code.substr(code.find("/") + 1);    
    int id = 0;    
    for (int i = 0; i < code.size(); i++) {        
        auto it = std::find(base.begin(), base.end(), code[i]);        
        if (it != base.end()) {
            int baseIndex = it - base.begin();            
            id += baseIndex * pow(base.size(), code.size() - i - 1);            
        } else {            
            return 0;
        }
    }
    return id;
}

/**
 * Check if an URL is valid based on the rules:
 * a) Regex valid
 * b) between 1 and 200 characters
 * 
 * @param url URL to validate
 * @return true if URL is valid
 **/
bool isValidURL(std::string url) {        
    std::regex regexFormat(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)");
    return url.size() > 0 && url.size() < 200 && std::regex_match(url, regexFormat);
}

/**
 *  Generate a short version of the provided URL.
 *  @param url provided URL
 *  @param customShortLink - Optional custom short link (defaults to "l.to")
 *  @return new short version of the URL
 */
std::string makeShortURL(std::string url, std::string customShortLink = "l.to") {           
    if (!isValidURL(url) || !isValidURL(customShortLink)) {
        return invalidURLMessage();
    }
    if (customShortLink[customShortLink.size() -1] != '/') {
        customShortLink += '/';
    }

    int id = save(url, EXTERNAL_DATABASE);    
    return customShortLink + encode(id, getBase());
}

/**
 *  Resolve a full URL from a provided short URL
 *  @param shortURL provided short URL
 *  @return Full and original version of the URL
 */
std::string getFullURL(std::string shortURL) {   
    if (!isValidURL(shortURL)) {
        return invalidURLMessage();
    }   

    int id = decode(shortURL, getBase());
    if (id == 0) {
        return invalidURLMessage();
    }    

    return get(id, EXTERNAL_DATABASE);
}

/**
 * Tests
 */
TEST_CASE("Tests - with a clean database")  //Starting with a clean database...
{         
    //URL format must be validated
    CHECK(makeShortURL("121") == "INVALID URL");           
    CHECK(makeShortURL("uol") == "INVALID URL");    
    CHECK(makeShortURL("http:/www.uol.com.br") == "INVALID URL");          
    CHECK(makeShortURL("http://www.uol.com.br", "alias!.to") == "INVALID URL");      
        
    //Given a URL, our service should generate a shorter and unique alias of it. 
    //This is called a short link. This link should be short enough to be easily copied 
    //and pasted into applications
    CHECK(makeShortURL("youtube.com") == "l.to/emjd");    

    //Resolve Full URL from short link provided
    CHECK(getFullURL("l.to/emjd") == "youtube.com");

    //Try to resolve a Full URL from an inexistent short link 
    CHECK(getFullURL("l.to/abcd") == "INVALID URL");

    //Users should optionally be able to pick a custom short link for their URL
    CHECK(makeShortURL("https://pt.wikipedia.org/wiki/Jair_Bolsonaro", "muito.mito") == "muito.mito/emje");

    //Valid URL size - 199 characters
    CHECK(makeShortURL("www.super-long-url.com/asdfasdhdflkasdjfhadjklfhadkljfhdlfkjaasdfhasdjklfhdklfjahdflkjasdhfasdkljfhasdklfjahdflkajsdhfasdkljfhadlfkjasdhdlaskdjfhasdlkfjhadlfkjshdflaksdjfhasdkljfhadlfkajhdflasdkjfha") == "l.to/emjf");

    //Invalid URL size - greater than 200 characters
    CHECK(makeShortURL("www.super-long-url.com/asdfasdhdflkasdjfhDadjklfhadkljfhdlfkjaasdfhasdjklfhdklfjahdflkjasdhfasdkljfhasdklfjahdflkajsdhfasdkljfhadlfkjasdhdlaskdjfhasdlkfjhadlfkjshdflaksdjfhasdkljfhadlfkajhdflasdkjfhDaz") == "INVALID URL");

    //Register 2000 FULL URLs, store their short links and Resolve them again, testing if they are the same
    std::vector<std::string> shortURLs;
    for (int i = 0; i < 2000; i++) {
        shortURLs.push_back(makeShortURL("www.uol.com.br/test" + std::to_string(i)));
    }
    for (int i = 0; i < 2000; i++) {
        CHECK(getFullURL(shortURLs[i]) == "www.uol.com.br/test" + std::to_string(i));
    }    
}