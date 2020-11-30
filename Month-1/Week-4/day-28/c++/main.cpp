/**
 * DAY-28 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include "../../../../dependencies/c++/color.hpp" //https://github.com/fengwang/colorize

const char SELECTED_LETTER_MARK = '!';

/**
 * Keeps searching the words.
 * @param board The board of letters
 * @param step An array of size 2, to represent the position X and Y on the board
 * @param dictionary Dictionary of valid words do find
 * @param width Width of the board
 * @param height Height of the board
 * @param executionStep The execution 'path' on the board until now
 * @param discovered Words discovered so far
 * @param markedBoard Representantion of the board to mark the used positions
 * @param currentWord The current word so far
 */ 
void keepSearching(std::vector<std::vector<char>>& board, int step[2], std::vector<std::string>& dictonary, int width, int height, std::vector<int*> executionSteps, std::vector<std::string>& discovered, std::vector<std::vector<char>>& markedBoard, std::string currentWord) {
    if (dictonary.size() == 0) {        
        return;
    }

    executionSteps.push_back(step); 
    currentWord += board[step[1]][step[0]];  
    
    for (auto &w : dictonary) {
        if (w == currentWord) {
            auto it = std::find(dictonary.begin(), dictonary.end(), w);
            if (it != dictonary.end()) {
                dictonary.erase(it);
            }    

            discovered.push_back(currentWord);

            for (int i = 0; i < executionSteps.size(); i++) {
                markedBoard[executionSteps[i][1]][executionSteps[i][0]] = SELECTED_LETTER_MARK;
            }
            return;
        }
    }    
  
    int stepEast[] = {step[0] + 1, step[1]};
    int stepWest[] = {step[0] - 1, step[1]};
    int stepSouth[] = {step[0], step[1] + 1};
    int stepNorth[] = {step[0], step[1] - 1};
    std::vector<int*> nextSteps = {stepEast, stepWest, stepSouth, stepNorth};

    for (int i = 0; i < nextSteps.size(); i++) {
        if (nextSteps[i][0] >= 0 && nextSteps[i][0] < width && nextSteps[i][1] >= 0 && nextSteps[i][1] < height) {            
            bool cleanPath = true;

            for (auto &s : executionSteps) {            
                if (s[0] == nextSteps[i][0] && s[1] == nextSteps[i][1]) {                    
                    cleanPath = false;
                    break;
                }
            }

            if (cleanPath) {
                keepSearching(board, nextSteps[i], dictonary, width, height, executionSteps, discovered, markedBoard, currentWord);
            } 
        }       
    }
}

/**
 * Outputs the resut.
 * 
 * @param board The board of letters
 * @param width Width of the board
 * @param height Height of the board
 * @param discovered Words discovered so far
 * @param markedBoard Representantion of the board to mark the used positions
 * @return Words found
 */ 
std::string output(std::vector<std::vector<char>>& board, int width, int height, std::vector<std::string>& discovered, std::vector<std::vector<char>>& markedBoard) {
    std::string r;
    const int BOARD_HEIGHT_INFLATE = 2; //Height inflated because each new cell is two characters vertically (the horizontal and vertical lines)
    const std::string DEFAULT = "Default";
    const std::string HIGHLIGHT_COLOR = "Cyan";
    const std::string HIGHTLIGHT_EFFECT = "Bold";

    std::cout << "\n\n";
    for (int py = 0; py <= height * BOARD_HEIGHT_INFLATE; py++) { 
        for (int px = 0; px < width; px++) {            
            std::string letter;            
            if (py % BOARD_HEIGHT_INFLATE != 0 && py != height * BOARD_HEIGHT_INFLATE) {
                letter += board[py / BOARD_HEIGHT_INFLATE][px];                
            }

            std::string borderColor = DEFAULT;
            if (py % 2 == 0) {
                std::cout << color::rize("+---", borderColor);
                if (px == width -1) {
                    std::cout << color::rize("+", borderColor);
                }
            } else {               
                std::string colorEffect = DEFAULT; 
                std::string attributeEffect = DEFAULT; 

                if (markedBoard[py / BOARD_HEIGHT_INFLATE][px] == SELECTED_LETTER_MARK) {
                    colorEffect = HIGHLIGHT_COLOR;
                    attributeEffect = HIGHTLIGHT_EFFECT;
                }

                std::cout <<  color::rize("| ", borderColor) << color::rize(letter, colorEffect, DEFAULT, attributeEffect);

                if (px == width - 1){
                    std::cout <<  color::rize(" |", borderColor);
                } else {
                    std::cout  <<  " ";
                }
            }            
        }        
         std::cout <<  "\n";
    }        

    std::cout <<  "\n";
    r = "[";
    for (int i = 0; i < discovered.size(); i++) {
        if (i > 0) {
            r += ",";
        }
        r += "\"" + discovered[i] + "\"";
    }    
    r += "]";
    
    std::cout << r << std::endl;
        
    return r;
}

/**
 * The Word Search.
 * @param board The board of letters
 * @param dictionary Dictionary of valid words do find
 * @return Words found
 */ 
std::string wordSearch(std::vector<std::vector<char>> board, std::vector<std::string> dictionary) {        
    int width = board[0].size();
    int height = board.size();               
    
    std::vector<std::string> discovered;
    std::vector<std::vector<char>> markedBoard = board;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int step[] = {i, j};
            std::vector<int*> executionSteps;            
            std::string currentWord;
            keepSearching(board, step, dictionary, width, height, executionSteps, discovered, markedBoard, currentWord);            
        }
    }

    return output(board, width, height, discovered, markedBoard);    
}

/**
 * Tests
 */
TEST_CASE("Tests")
{           
    CHECK(wordSearch({{'o','a','a','n'},
                      {'e','t','a','e'},
                      {'i','h','k','r'},                                
                      {'i','f','l','v'}}, {"oath","eat"}) == "[\"oath\",\"eat\"]");        

    CHECK(wordSearch({{'G','A','X','M','I','T','O'},
                      {'U','D','T','L','U','L','A'},
                      {'W','O','Z','S','O','L','U'},                                
                      {'O','R','A','N','O','S','L'}}, 
                      {"MITO","LULA", "GADO"}) == "[\"GADO\",\"MITO\",\"LULA\"]");
}