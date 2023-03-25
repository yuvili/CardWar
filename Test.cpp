#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include "doctest.h"

TEST_CASE("Create 2 players with their names"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.getName() == "Alice");
    CHECK(p2.getName() == "Bob");

    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() + p2.stacksize() == 52);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("The game playTurn function plays a turn correctly"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();

    CHECK(game.lastTurn().size() == 2);
    CHECK(p1.stacksize() == 27);
    CHECK(p2.stacksize() == 25);
    CHECK(game.lastTurnResults() == p1.getName() + " wins");
}

TEST_CASE("The game playTurn function hadles a draw correctly"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();

    CHECK(game.lastTurnResults() == "Draw");
}

TEST_CASE("The game playTurn function hadles a draw correctly when player's pail is empty"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    game.playTurn();

    CHECK(game.lastTurnResults() == "Draw");
    CHECK(game.gameOver());
    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() == 0);
}

TEST_CASE("The game playAll function plays all the turns untill the end correctly"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    CHECK(game.gameOver());
    CHECK(game.winner() == p1.getName());
    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
    CHECK(p1.cardesTaken() > p2.cardesTaken());
}