#include "player.hpp"
#include <string>

namespace ariel{
Player::Player(std::string name)
    : p_name(name), cards(), cardsWon()
{}

int Player::stacksize(){
    return cards.size();
}

int Player::cardesTaken(){
    return cardsWon.size();
}

void Player::addCard(Card new_card){
    cards.push_back(new_card);
}

void Player::addWonCard(Card won_card){
    cardsWon.push_back(won_card);
}

std::string Player::getName(){
    return p_name;
}
}