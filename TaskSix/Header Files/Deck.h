//
// Created by Michael on 29.11.2020.
//

#ifndef CPP_LAB_FOUR_DECK_H
#define CPP_LAB_FOUR_DECK_H


#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();
    virtual ~Deck();
    Card getCardAt(size_t index);
    Card drawTopCard();
    size_t getCardsLeft() const;
    void showDeck();
private:
    std::vector<Card> deck;
    size_t cardsLeft = 52;
};


#endif //CPP_LAB_FOUR_DECK_H
