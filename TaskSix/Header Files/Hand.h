//
// Created by Michael on 30.11.2020.
//

#ifndef CPP_LAB_FOUR_HAND_H
#define CPP_LAB_FOUR_HAND_H


#include "Deck.h"

class Hand{
public:
    Hand();
    size_t getTotalValue();
    void addCard(const Card& card);
    void showDeck();
    void resetDeck();
    virtual ~Hand();
    bool isBlackjack();
    friend std::ostream& operator<<(std::ostream &out, const Hand &hand);
private:
    static const size_t maxCards = 12;
    size_t numOfAces = 0;
    bool blackjack = false;
    std::vector<Card> deck;
    size_t totalCards = 0;
};


#endif //CPP_LAB_FOUR_HAND_H
