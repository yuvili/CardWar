#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "card.hpp"

namespace ariel{
class Player{
    private:
        std::string p_name;
        std::vector<Card> cards;
        std::vector<Card> cardsWon;
    
    public:
        Player(std::string name);
        int stacksize();
        int cardesTaken();
        void addCard(Card new_card);
        void addWonCard(Card won_card);
        std::string getName();

        Player() = default;
};
}
#endif