/**
 * DAY-80 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include "../../../../dependencies/c++/indicators.hpp" //https://github.com/p-ranav/indicators
#include <random>

/**
 * Dispatch a job in another thread
 * @param barWitdh Progress bar width
 * @param fillContent Fill content
 * @param leadContent Lead content
 * @param remainderContent Remainder content
 * @param endContent End content
 * @param color Color
 * @param fontSytle Font Style
 * @param sleep Ammount of sleep
 * @param prefixText Prefix text
 * @param postfixText Postfix text
 * @param incrementFactor Increment Factor
 */ 
void dispatchProgress(int barWitdh, 
                      std::string startContent, 
                      std::string fillContent, 
                      std::string leadContent, 
                      std::string remainderContent, 
                      std::string endContent, 
                      indicators::Color color, 
                      indicators::FontStyle fontStyle, 
                      int sleep, 
                      std::string prefixText, 
                      std::string postfixText,
                      int incrementFactor) {
                           
    indicators::ProgressBar p{
            indicators::option::BarWidth{barWitdh},
            indicators::option::Start{startContent},
            indicators::option::Fill{fillContent},
            indicators::option::Lead{leadContent},
            indicators::option::Remainder{remainderContent},
            indicators::option::End{endContent},
            indicators::option::ForegroundColor{color},
            indicators::option::FontStyles{std::vector<indicators::FontStyle>{fontStyle}}};

    std::atomic<size_t> progress{0};

    //define the job
    auto job = [&p, &progress, &postfixText, &prefixText, &sleep, &incrementFactor]() {
        bool hasOptions = !postfixText.empty();

        while (true) {                          
            std::string text = postfixText.empty() ? prefixText : postfixText;
            if (p.current() + 1 >= 100) {
                text += "...Done";
            } else {
                text += "..." + std::to_string(p.current()) + "% ";
            }
            if (postfixText.empty()) {
                p.set_option(indicators::option::PrefixText{text});   
            } else {
                p.set_option(indicators::option::PostfixText{text});
            }

            if (p.is_completed()) {                 
                break;
            }

            progress += 1;                    
            p.tick();

            std::this_thread::sleep_for(std::chrono::milliseconds(sleep));            
        }
    };

    //start the job in a new thread
    std::thread thread(job);
    thread.join(); //wait for it     
}

/**
 * Make it look like you are working.
 * @param buzzwordsFilename The buzzwords file to get random tasks descriptions
 * @param repeat Number of times to repeat process
 * @param count Counter of repetitions
 * @return Number of repetitions
 */ 
int fakeWork(std::string buzzwordsFilename, const int repeat = 1, int count = 0) {    
    std::ifstream file(buzzwordsFilename, std::ifstream::in); //file open for reading
    if (!file) {                
        return -1;
    }     
    
    //get available buzzwords 
    std::vector<std::string> buzzwords;
    std::string buzzword;
    while (std::getline(file, buzzword, '\n')) { //read the file, line by line
        buzzwords.push_back(buzzword);
    }
    //get available colors
    const std::vector<indicators::Color> colors = {indicators::Color::cyan, indicators::Color::blue, indicators::Color::green, indicators::Color::grey, indicators::Color::magenta, indicators::Color::red, indicators::Color::white, indicators::Color::yellow};
        

    std::random_device rd; // only used once to initialise (seed) engine
    std::mt19937 engine(rd());// random-number engine used (Mersenne-Twister in this case)                                          
    std::uniform_int_distribution<int> uniColors(0, colors.size() - 1); //get random color
    std::uniform_int_distribution<int> uniBuzzwords(0, buzzwords.size() - 1); //get random buzzword
    std::uniform_int_distribution<int> uniSleep(10, 100); //get random sleep

    indicators::show_console_cursor(false);
    //execute two different types of job per repetition
    while (++count <= repeat) {
        dispatchProgress(50, "[", "■", "■", " ", " ]", colors[uniColors(engine)], indicators::FontStyle::bold, uniSleep(engine), "", buzzwords[uniBuzzwords(engine)], 10);        
        dispatchProgress(0, "", "", "", "", "", colors[uniColors(engine)], indicators::FontStyle::bold, uniSleep(engine), buzzwords[uniBuzzwords(engine)], "", 10);        
    }
    indicators::show_console_cursor(true);

    return --count;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(fakeWork("../../../../assets/buzzwords.txt", 3) == 3);
}