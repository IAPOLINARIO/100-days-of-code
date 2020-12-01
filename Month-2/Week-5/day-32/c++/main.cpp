/**
 * DAY-32 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <list>

/**
 * Track the player ranking using Dense Ranking.
 * @param rankedScores the ranked scores
 * @param playerScores the player scores
 * @return Player Ranking for each game
 */ 
std::vector<int> playerRank(std::vector<int> rankedScores, std::vector<int> playerScores) {    
    
    std::vector<int> playerRanking;
    //int playerGame = 0; //leaderboard updated version of the challenge (disabled)
    for (auto &p : playerScores) {
        std::list<int> unifiedScoresAux;
        std::list<int> rankedScoresAux(rankedScores.begin(), rankedScores.end());
        unifiedScoresAux.merge(rankedScoresAux);
        
        //leaderboard updated version of the challenge (disabled)
        /*for (int i = 0; i < playerScores.size(); i++) {
            if (i <= playerGame) {
                unifiedScoresAux.push_back(playerScores[i]);                
            } else {
                break;
            }
        }
        playerGame++;*/
        unifiedScoresAux.push_back(p); //comment this if the leaderboard updated version is active


        unifiedScoresAux.sort();
        unifiedScoresAux.unique();
        
        int index = 0;
        for (auto &s : unifiedScoresAux) {
            if (s == p) {
                playerRanking.push_back(unifiedScoresAux.size() - index);
                break;
            }
            index++;
        }
    }

    return playerRanking;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(playerRank({100, 90, 90, 80}, {70, 80, 105}) == std::vector<int>{4, 3, 1});
    CHECK(playerRank({100, 90, 90, 80}, {106, 107, 105}) == std::vector<int>{1, 1, 1});
    CHECK(playerRank({100, 90, 90, 80}, {90, 80, 1}) == std::vector<int>{2, 3, 4});
    CHECK(playerRank({100, 90, 90, 80, 75, 60}, {50, 65, 77, 90, 102}) == std::vector<int>{6, 5, 4, 2, 1});
    CHECK(playerRank({100, 100, 50, 40, 40, 20, 10}, {5, 25, 50, 120}) == std::vector<int>{6, 4, 2, 1});
}
