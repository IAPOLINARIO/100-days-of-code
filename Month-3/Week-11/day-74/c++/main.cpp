/**
 * DAY-74 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#define CPPHTTPLIB_OPENSSL_SUPPORT //SSL support is available with CPPHTTPLIB_OPENSSL_SUPPORT. libssl and libcrypto should be linked
#include "../../../../dependencies/c++/httplib.h" //https://github.com/yhirose/cpp-httplib (for server support, it also needs to be linked with libpthread)

#include "../../../../dependencies/c++/json.hpp" //https://github.com/nlohmann/json

//The Twitter Bearer Token for API v2
const char *TWITTER_BEARER_TOKEN = ""; //put the Twitter Bearer Token for API v2
//The Programmable Search Engine ID from Google (For Google Image Search)
const std::string GOOGLE_PROGRAMMABLE_SEARCH_ENGINE_FOR_IMAGES_ON_TWITTER_ID = ""; //put The Programmable Search Engine ID from Google (For Google Image Search)
//The Programmable Search Engine API KEY from Google (For Google Image Search)
const std::string GOOGLE_PROGRAMMABLE_SEARCH_ENGINE_FOR_IMAGES_ON_TWITER_API_KEY = ""; //put The Programmable Search Engine API KEY from Google (For Google Image Search)

/**
 * THE CATTLEMETER
 * 
 * @param twitterUsername The twitter username to analyse
 * @param lasTweetsToAnalyze Number of last tweets to analyse (default 30)
 * @param lasTweetsToAnalyzeWordsRepetitionLimitRatio Limit ratio of words repeated based on the total of last tweets to be considered excessive (default 50%)
 * @param lastTweetsRepetitionLimitRaio Limit ratio of repetition in tweets (default 50%)
 * @param inactivityYearsLimit Inactivity years allowed without triggering the Cattlemeter (default 1 year)
 * @param minBioValidSize Minimum BIO description size (default 10)
 * @param tweetCountLimit Limit of excessive tweet count (default 10000)
 * @param followersMinLimit Limit of minimum follwers (default 2)
 * @param follownigMaxLimit Limit of maximum following (default 2000)
 * @param stockImageTriggerSearchLimit Stock image detection search trigger (default 500)
 * @param defaultProfileImgs List of 'egghead' profile images (default current Twitter image )
 * @param incoherentTerms List of 'incoherent' terms that could trigger the Cattlemeter
 * @return THE CATTLEMETER SCORE
 */ 
int gadoDetect(std::string twitterUsername, int lasTweetsToAnalyze = 30, double lasTweetsToAnalyzeWordsRepetitionLimitRatio = 0.5, double lastTweetsRepetitionLimitRaio = 0.5, int inactivityYearsLimit = 1, size_t minBioValidSize = 10, int tweetCountLimit = 10000, int followersMinLimit = 2, int follownigMaxLimit = 2000, int stockImageTriggerSearchLimit = 500, std::vector<std::string> defaultProfileImgs = {"https://abs.twimg.com/sticky/default_profile_images/default_profile_normal.png"}, std::vector<std::string> incoherentTerms = {}) {
    const int ERROR = -1;
    const int HTTP_RESPONSE_OK = 200;
    const int SCORE_INCREMENT = 10;
    const int SECONDS_YEAR = 31536000;

    int score = 0;
    
    //setup initial endpoints
    const std::string TWITTER_API_SERVER = "api.twitter.com";
    const std::string TWITTER_API_GET_PUBLIC_METRICS_BY_USERNAME = "/2/users/by/username/" + twitterUsername + "?user.fields=public_metrics,description,profile_image_url,verified";    
    
    httplib::SSLClient cli(TWITTER_API_SERVER);    
    cli.set_bearer_token_auth(TWITTER_BEARER_TOKEN); //setup bearer token header request

    //Get basic user info    
    auto res = cli.Get(TWITTER_API_GET_PUBLIC_METRICS_BY_USERNAME.c_str()); //call API_GET_PUBLIC_METRICS_BY_USERNAME
    if (res->status != HTTP_RESPONSE_OK) {  
        std::cout << '\n' << twitterUsername << ":\n" << "Error connecting. Status -> " << res->status << '\n';
        return ERROR; //error connecting
    }    
    //parse results
    nlohmann::json jsonResponse = nlohmann::json::parse(res->body);

    //check if user is valid
    if (jsonResponse["data"]["id"].is_null()) {
        std::cout << '\n' << twitterUsername << ":\n" << "Invalid user" << '\n';
        return ERROR; 
    }

    //get User ID (needed for further calls)
    std::string userId = jsonResponse["data"]["id"];

    //check if it is a verified account
    bool verifiedAccount = jsonResponse["data"]["verified"];
    
    //RULE: No Bio
    std::string bio = jsonResponse["data"]["description"];
    if (bio.size() < minBioValidSize) {
        score += SCORE_INCREMENT;
    }

    if (!verifiedAccount) { //for verified accounts, consider images OK
        //get Profile Img 
        std::string profileImgUrl = jsonResponse["data"]["profile_image_url"];

        //RULE - An Egghead
        bool isEgghead = false;
        for (auto &i : defaultProfileImgs) {
            if (i == profileImgUrl) {
                isEgghead = true;
                score += SCORE_INCREMENT;
                break;
            }
        }

        if (!isEgghead) {
            //RULE - Stock Profile Images
            const std::string GOOGLE_CUSTOM_SEARCH_API_SERVER = "customsearch.googleapis.com";
            const std::string GOOGLE_CUSTOM_SEARCH_API_GET = "/customsearch/v1?q=" + profileImgUrl + "&key=" + GOOGLE_PROGRAMMABLE_SEARCH_ENGINE_FOR_IMAGES_ON_TWITER_API_KEY + "&cx=" + GOOGLE_PROGRAMMABLE_SEARCH_ENGINE_FOR_IMAGES_ON_TWITTER_ID;
            
            httplib::SSLClient cliImgSearch(GOOGLE_CUSTOM_SEARCH_API_SERVER);
            cliImgSearch.set_compress(true);            
            auto resImgSearch = cliImgSearch.Get(GOOGLE_CUSTOM_SEARCH_API_GET.c_str());

            if (resImgSearch->status != HTTP_RESPONSE_OK) {  
                std::cout << '\n' << twitterUsername << ":\n" << "Error connecting. Status -> " << resImgSearch->status << '\n';
                return ERROR; //error connecting
            }
            //parse results
            nlohmann::json jsonResponseImgSearch = nlohmann::json::parse(resImgSearch->body);
            if (!jsonResponseImgSearch["searchInformation"].is_null() && !jsonResponseImgSearch["searchInformation"]["totalResults"].is_null()) {                
                std::string totalResultsFromGoogleAPI = jsonResponseImgSearch["searchInformation"]["totalResults"]; //results are in string format
                int profileImgSearchResults = std::atoi(totalResultsFromGoogleAPI.c_str());
                if (profileImgSearchResults > stockImageTriggerSearchLimit) {
                    score += SCORE_INCREMENT;
                }
            }
        } else {
            //if the user is an 'egghead', consider the points of the stock image RULE as well
            score += SCORE_INCREMENT;
        }        
    }

    //Confusing Screen Name / URL Combination
    //nameToUserNameMismatch is TRUE if there aren't anuy match between Name and UserName
    const std::string name = jsonResponse["data"]["name"];
    std::istringstream iss(name);
    std::string value;
    bool nameToUserNameMismatch = true;
    while (std::getline(iss, value, ' ') && nameToUserNameMismatch) {
        //need to do a case insensitve search        
        auto it = std::search(twitterUsername.begin(), twitterUsername.end(), value.begin(), value.end(), [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); });
        nameToUserNameMismatch = it == twitterUsername.end();        
    }
    //RULE: Confusing Screen Name / URL Combination
    if (nameToUserNameMismatch) {
        score += SCORE_INCREMENT;
    }            

    //RULE: An Unrealistic Amount of Tweets - Tweet count
    int tweetCount = jsonResponse["data"]["public_metrics"]["tweet_count"];
    if (tweetCount > tweetCountLimit) {
        score += SCORE_INCREMENT;
    }
    
    //RULE: No or Low Follower Counts
    int followersCount = jsonResponse["data"]["public_metrics"]["followers_count"];
    if (followersCount < followersMinLimit) {
        score += SCORE_INCREMENT;
    }
    
    //RULE: Follows 2,001 People
    auto followingCount = jsonResponse["data"]["public_metrics"]["following_count"];
    if (followingCount > follownigMaxLimit) {
        score += SCORE_INCREMENT;
    }

    //configure endpoint of user's tweets    
    const std::string TWIITER_API_GET_TWEETS_BY_USER_ID = "/2/users/" + userId + "/tweets?tweet.fields=created_at,public_metrics&max_results=" + std::to_string(lasTweetsToAnalyze);

    //Get Last Tweets from user    
    res = cli.Get(TWIITER_API_GET_TWEETS_BY_USER_ID.c_str());
    if (res->status != HTTP_RESPONSE_OK) {        
        std::cout << '\n' << twitterUsername << ":\n" << "Error connecting. Status -> " << res->status << '\n';
        return ERROR; //error connecting
    }
    //parse results
    jsonResponse = nlohmann::json::parse(res->body);

    //RULE: Has Not Tweeted in Years  
    double years = -1;
    if (!jsonResponse["data"][0].is_null()) {
        std::string timestamp = jsonResponse["data"][0]["created_at"];
        std::tm tmLastTweet = {};
        std::stringstream ss(timestamp);
        ss >> std::get_time(&tmLastTweet, "%y-%m-%d");
        
        time_t now = time(0);        
        years =  difftime(now, mktime(&tmLastTweet)) / SECONDS_YEAR;    
    }
    if (years == -1 || years > inactivityYearsLimit) {
        score += SCORE_INCREMENT;
    }
    
    //RULES: 
    //- No Interaction With Others 
    //- Excessive Duplicate Tweets 
    //- Incoherent Tweets
    std::map<std::string, int> repWordsMap; //dictionary of repeated words
    bool hasIncoherentTweet = false; //incoherent Tweets    
    bool hasReply = false;
    bool hasRetweet = false;
    for (auto &t : jsonResponse["data"]) { //check the last tweets if there are no @replies or retweets        
        if (!hasReply) {
            hasReply = t["public_metrics"]["reply_count"] > 0;
        }
        if (!hasRetweet) {
            hasRetweet = t["public_metrics"]["retweet_count"] > 0;
        }
        
        if (!t["text"].is_null()) {
            std::istringstream iss((std::string) t["text"]);
            std::string word;        
            while (std::getline(iss, word, ' ')) {
                if (word != " ") {
                    repWordsMap[word] += 1;         
                    
                    if (!hasIncoherentTweet && !incoherentTerms.empty()) {
                        auto it = std::find(incoherentTerms.begin(), incoherentTerms.end(), word);
                        hasIncoherentTweet = it != incoherentTerms.end();
                    }
                }
            }
        }
    }
    int excessiveDuplicatedWords = 0;
    for (auto &w : repWordsMap) {        
        excessiveDuplicatedWords += (w.second > (lasTweetsToAnalyzeWordsRepetitionLimitRatio * lasTweetsToAnalyze) ) ? 1 : 0; //if greater than half of the last batch of tweets...
    }
    double repTweetsRatio = (static_cast<double>(excessiveDuplicatedWords) / lasTweetsToAnalyze);
    //RULE: No Interaction With Others 
    if (!hasReply && !hasRetweet) {
        score += SCORE_INCREMENT;
    }    
    //RULE: Excessive Duplicate Tweets 
    if (repTweetsRatio > lastTweetsRepetitionLimitRaio) {
        score += SCORE_INCREMENT;
    }
    //RULE: Incoherent Tweets
    if (hasIncoherentTweet) {
        score += SCORE_INCREMENT;
    }        

    //print result
    std::cout << '\n' << name << " (" << twitterUsername << ") result:\n";
    std::string resultDescription;
    if (score < 20)  {
        resultDescription = "Not a cattle";
    } else {
        if (score >= 20 && score <= 80) {
            resultDescription = "Sounds like a cattle (muhhhh)";
        } else {
            if (score > 80 && score <= 100 ) {
                resultDescription = "It's definetely a cattle ! Avoid it !";
            } else {
                resultDescription = "Too much cattle! :cow:";
            }
        }
    }
    std::cout << resultDescription << '\n';

    //return score
    return score;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{    
    CHECK(gadoDetect("teste18427839") >= 20);
    CHECK(gadoDetect("realDonaldTrump") != -1);
    CHECK(gadoDetect("LucianoHuck") != -1);
    CHECK(gadoDetect("jairbolsonaro") != -1);
    CHECK(gadoDetect("CarlosBolsonaro") != -1);
    CHECK(gadoDetect("Haddad_Fernando") != -1);
    CHECK(gadoDetect("GuilhermeBoulos") != -1);
    CHECK(gadoDetect("BrazilFight") >= 20);
    CHECK(gadoDetect("augustosnunes") != -1);
    CHECK(gadoDetect("MarceloSCCP4_5") >= 20);
}


