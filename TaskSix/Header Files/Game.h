//
// Created by Michael on 29.11.2020.
//

#ifndef CPP_LAB_FOUR_GAME_H
#define CPP_LAB_FOUR_GAME_H


#include "Player.h"
#include "Deck.h"

class Game {
public:
    Game(int startingPlayerCash);
    void startGame(size_t bet);
    void showInfo();
    void addCardToPlayer();
    void addCardToDealer();
    void prompt();
    void surrender();
    void endGame();
    size_t getTotalCash();
    //something
private:
    std::vector<Deck> decks;
    Player dealer;
    Player user;
    int bet;
};


#endif //CPP_LAB_FOUR_GAME_H
