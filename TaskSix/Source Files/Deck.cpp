//
// Created by Michael on 29.11.2020.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "../Header Files/Deck.h"

std::string faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
Deck::Deck(){
    std::string cards[52];
    for(int i = 0; i<13; i++){
        cards[i] = faces[i]+"♠";
    }
    for(int i = 13; i<26; i++){
        cards[i] = faces[i-13]+"♥";
    }
    for(int i = 26; i<39; i++){
        cards[i] = faces[i-26]+"♦";
    }
    for(int i = 39; i<52; i++){
        cards[i] = faces[i-39]+"♣";
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (std::begin(cards), std::end(cards), std::default_random_engine(seed));
    for(auto & card : cards){
       deck.emplace_back(card);
    }
}

Deck::~Deck() {
}

Card Deck::getCardAt(size_t index) {
    return deck.at(index);;
}
Card Deck::drawTopCard() {
    cardsLeft--;
    return deck.at(cardsLeft);
}

void Deck::showDeck() {
    for(size_t i =0; i <cardsLeft; i++){
        std::cout<<deck.at(cardsLeft)<<std::endl;
    }
}

size_t Deck::getCardsLeft() const {
    return cardsLeft;
}

