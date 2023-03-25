#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using namespace std;

#include "player.hpp"

namespace ariel{

class Game{
    private:
        Player player1;
        Player player2;
        std::vector<Card> pile;
        std::vector<Card> cards_pack;
        std::vector<std::string> logs;

    public:
        Game(Player p1, Player p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        bool gameOver();
        std::vector<Card> lastTurn();
        std::string lastTurnResults();
        std::string winner();
};
}
#endif