#include "game.hpp"
#include "player.hpp"

namespace ariel {
Game::Game(Player p1, Player p2)
    : player1(p1), player2(p2), pile(), cards_pack(), logs()
{}

void Game::playTurn(){
    return;
}

void Game::printLastTurn(){
    return;
}

void Game::playAll(){
}

void Game::printWiner(){

}

void Game::printLog(){

}

void Game::printStats(){

}

bool Game::gameOver(){
    return true;
}

std::vector<Card> Game::lastTurn(){
    return pile;
}

std::string Game::lastTurnResults(){
    return "";
}

std::string Game::winner(){
    return "";
}
}