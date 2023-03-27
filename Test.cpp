#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include "doctest.h"

TEST_CASE("Create 2 players with their names"){
    CHECK_NOTHROW(Player p1("Alice"));
    CHECK_NOTHROW(Player p2("Bob"));
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() + p2.stacksize() == 52);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("The game playTurn function plays a turn correctly"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game game(p1, p2));
    Game game(p1, p2);
    game.playTurn();

    CHECK(p2.stacksize() == p1.stacksize());
    CHECK(p1.stacksize() == 25);
    CHECK(p1.cardesTaken() == 1);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The game playTurn function hadles a draw correctly"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();

    CHECK(p1.stacksize() == 23); 
    CHECK(p2.stacksize() == p1.stacksize());
    CHECK(p1.stacksize() == 23);
    CHECK(p1.cardesTaken() == 3); // p1 won in the draw
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("The game playTurn function hadles a draw correctly when player's pail is empty"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    game.playTurn();

    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() == 0);
}

TEST_CASE("The game playAll function plays all the turns untill the end correctly"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() == 0);

    Player p3("Chris");
    Player p4("David");
    CHECK_NOTHROW(Game game(p3, p4));
}