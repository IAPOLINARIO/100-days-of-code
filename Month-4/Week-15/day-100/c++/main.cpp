/**
 * FINAL DAY-100 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <random> //for random generation
#include <mutex> //for the std::mutex syncronization primitive
#include <condition_variable> //for the std::condition_variable syncronization primitive
#include <functional> //function as arguments
#include <thread> //for the std::thread

/**
 * Helper function to output messages to stdout
 * @param message Message to output
 */ 
void outputMessage(const std::string message) {
    std::cout << message << std::endl;
}

/**
 * Outputs Hello World using an external linked ASM against the C++ program (i_o.asm / i_o.o).
 * See Makefiles for more details.
 * 
 * The i_o.asm exported Global 'InputAndOutputMessageFromExternalLinkedAssembly' receives a char 
 * pointer as argument with the message and returns back the same content. The content is received as
 * a char pointer as well.
 * 
 * Notice the 'extern "C"" calling, it avoids name mangling from the C++ compiler, so the Global
 * defined in the ASM is located from C++ code. 
 */ 
extern "C" char* InputAndOutputMessageFromExternalLinkedAssembly(const char* s);
void helloWorldFromLinkedAssembly(void)  {
    const std::string HELLO_WORLD = "HELLO WORLD FROM EXTERNAL LINKED ASSEMBLY (i_o.asm / i_o.o)";
    char* content = InputAndOutputMessageFromExternalLinkedAssembly(HELLO_WORLD.c_str());
    outputMessage(std::string(content));    
}

/**
 * Outputs Hello World from Hexadecimal content.
 */ 
void helloWorldInHexadecimal(void) {
    const char content[] = { 0x48, 0x45, 0x4C, 0x4C, 0x4F, 0x20, 0x57, 0x4F, 0x52, 0x4C, 0x44, 0x20, 0x46, 0x52, 0x4F, 0x4D, 0x20, 0x48, 0x45, 0x58, 0x41, 0x44, 0x45, 0x43, 0x49, 0x4D, 0x41, 0x4C, 0x00 };
    outputMessage(std::string(content));
}

/**
 * Outputs Hello World using Random Generation.
 * Multiples attempts are necessary to build the sentence.
 */ 
void helloWorldRandom(void) {
   const std::string HELLO_WORLD = "HELLO WORLD FROM MULTIPLE RANDOM ATTEMPTS";
   std::random_device rd; 
   std::mt19937 engine(rd());
   std::uniform_int_distribution<int> u(0, HELLO_WORLD.size() - 1);
   int index = 0;
   std::string output;
   while (index < HELLO_WORLD.size()) {
       const int randomIndex = u(engine);
       if (randomIndex == index) {
           output += HELLO_WORLD[randomIndex];
           index++;
       }
   }
   outputMessage(output);
}

/**
 * Ouputs Hello World using multiple threads (102 - one for each character of the expected output).
 
 * Since all 102 threads are running in parallel, it uses some synchronization primitives 
 * (mutex, locks and condition variable) to avoid problemas in the generation order of the output.
 * 
 * Each thread is running a lambda which captures the output, mutex and condition variable and
 * each instance receives the target size to check if its the right moment to update the ouput
 * and the target character.
 */ 
void helloWorldMultipleThreads(void) {
    const std::string EXPECTED = "HELLO WORLD FROM 102 THREADS WITH LAMBDA, MUTEX, CONDITION VARIABLE AND LOCK SYNCHRONIZATION PRIMITIVE";
    std::string output;
    std::mutex mutex; //MUTEX Synchronization primitive
    std::condition_variable cv; //CONDITION VARIABLE synchronization primitive
    
    const auto helloThreadBuilder = [&output, &mutex, &cv](const size_t target, const char c) {
        std::unique_lock<std::mutex> lock(mutex);
        while (output.size() != target) {
            cv.wait(lock); //the output is not in the correct order, wait for some other thread
        }
        output += c;
        cv.notify_all(); //notify all waiters
    };
        
    std::thread threads[EXPECTED.size()];
    for (int i = EXPECTED.size() - 1; i >= 0; i--) {
        threads[i] = std::thread(helloThreadBuilder, i, EXPECTED[i]); //start threads
    }
    for (auto &t : threads) {       
       t.join(); 
    }
    outputMessage(output);
}

/**
 * Main function.
 * It has a vector of std::functions, each one with a different implementation of Hello World.
 * It randomly select one of the options and executes it.
 * 
 * @return 0 for success
 */ 
int helloWorld(void) {    
    const std::vector<std::function<void (void)>> options = { helloWorldFromLinkedAssembly, 
                                                              helloWorldInHexadecimal, 
                                                              helloWorldRandom, 
                                                              helloWorldMultipleThreads 
                                                            };
    
    std::random_device rd; 
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> u(0, options.size() - 1);

    options[u(engine)](); //execute the random-selected Hello World implementation

    return 0;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    const size_t TEST_LOAD = 35;
    std::cout << "Running " << TEST_LOAD << " random tests" << std::endl;
    for (size_t i = 0; i < TEST_LOAD; i++) {
        CHECK(helloWorld() == 0);
    }
}