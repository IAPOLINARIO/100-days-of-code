/**
 * DAY-50 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Return the winner or tie results of a Tic Tac Toe game.
 * Inputs will be taken from player1 as **"X"**, player2 as **"O"**, and empty spaces as **"#"**
 * 
 * @param g char[3][3] array of the game
 * @return Message of the result of the game
 */ 
std::string ticTacToe(char g[3][3]) {
    char p = '#';

    if (g[0][0] == g[0][1] && g[0][0] == g[0][2] && g[0][0] != '#') {
        p = g[0][0];
    } else {
        if (g[1][0] == g[1][1] && g[1][0] == g[1][2] && g[1][0] != '#') {
            p = g[1][0];
        } else {
            if (g[2][0] == g[2][1] && g[2][0] == g[2][2] && g[2][0] != '#') {
                p = g[2][0];
            } else {
                if (g[0][0] == g[1][0] && g[0][0] == g[2][0] && g[0][0] != '#') {
                    p = g[0][0];
                } else {
                    if (g[0][1] == g[1][1] && g[0][1] == g[2][1] && g[0][1] != '#') {
                        p = g[0][1];
                    } else {
                        if (g[0][2] == g[1][2] && g[0][2] == g[2][2] && g[0][2] != '#') {
                            p = g[0][2];
                        } else {
                            if (g[0][0] == g[1][1] && g[0][0] == g[2][2] && g[0][0] != '#') {
                                p = g[0][0];
                            } else {
                                if (g[2][0] == g[1][1] && g[2][0] == g[0][2] && g[2][0] != '#') {
                                    p = g[2][0];
                                }   
                            }  
                        }
                    }
                }
            }
        }    
    }

    return p == 'X' ?  "Player 1 wins" : p == 'O' ? "Player 2 wins" : "It's a Tie";
}


/**
 * Tests
 */
TEST_CASE("Tests")
{
    char game1[3][3] = {{'X', 'O', 'O'},
                       {'O', 'X', 'O'},
                       {'O', '#', 'X'}};

    CHECK(ticTacToe(game1) == "Player 1 wins");

    char game2[3][3] = {{'X', 'O', 'O'},
                        {'O', 'X', 'O'},
                        {'X', '#', 'O'}};
                       
    CHECK(ticTacToe(game2) == "Player 2 wins");

    char game3[3][3] = {{'X', 'X', 'O'},
                        {'O', 'X', 'O'},
                        {'X', 'O', '#'}};
                       
    CHECK(ticTacToe(game3) == "It's a Tie");    

    char game4[3][3] = {{'X', 'X', 'O'},
                        {'X', 'O', 'O'},
                        {'O', 'O', '#'}};
                       
    CHECK(ticTacToe(game4) == "Player 2 wins");        
}