//
// Created by Michael on 29.11.2020.
//

#include "../Header Files/Game.h"
#include <ctime>
#include <random>



Game::Game(int startingPlayerCash) {
    for(int i = 0; i<4; i++) decks.emplace_back(Deck());
    std::cout <<"У вас "<<startingPlayerCash<<std::endl;
    user = Player();
    user.totalCash = startingPlayerCash;
    dealer = Player();
}

void Game::showInfo() {
    printf("Колоды: [%u] [%u] [%u] [%u]\n", decks.at(0).getCardsLeft(), decks.at(1).getCardsLeft(), decks.at(2).getCardsLeft(), decks.at(3).getCardsLeft());
    std::cout<<"Дилер: "<<dealer.hand<<std::endl;
    std::cout<<"Вы: "<<user.hand<<std::endl;

}

void Game::addCardToPlayer() {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 3);
    user.hand.addCard(decks.at(uid(gen)).drawTopCard());
}
void Game::addCardToDealer() {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 3);
    dealer.hand.addCard(decks.at(uid(gen)).drawTopCard());
}

void Game::prompt() {
    std::cout<<"1. Хватит"<<std::endl;
    std::cout<<"2. Еще"<<std::endl;
    std::cout<<"3. Саррендер"<<std::endl;
    int action;
    std::cin>>action;
    switch (action) {
        case 1:
            endGame();
            break;
        case 2:
            addCardToPlayer();
            showInfo();
            prompt();
            break;
        case 3:
            surrender();
            endGame();
            break;
        default:
            std::cout<<"Неверное действие"<<std::endl;
            prompt();
            break;
    }
}
void Game::startGame(size_t _bet) {
    if(user.totalCash<_bet){
        throw std::out_of_range("not enough money");
    }
    bet = _bet;
    user.totalCash-=bet;

    addCardToPlayer();
    addCardToPlayer();
    addCardToDealer();
}
void Game::endGame() {
    std::cout<<"Игра окончена."<<std::endl;
    addCardToDealer();
    showInfo();
    size_t userScore = 0;
    bool userLost = false;
    try{
        userScore = user.hand.getTotalValue();
    } catch (std::overflow_error) {
        std::cout<<"У вас больше 21, и поэтому вы проиграли. Вы потеряли "<<bet<<"."<<std::endl;
        std::cout <<"У вас "<<user.totalCash<<std::endl;
        user.hand.resetDeck();
        dealer.hand.resetDeck();
        return;
    }
    size_t dealerScore = dealer.hand.getTotalValue();
    std::cout<<"У дилера "<<dealerScore<<"."<<std::endl;
    std::cout<<"У вас "<<userScore<<"."<<std::endl;

    if(userScore==21){
        std::cout<<"У вас 21 очко. Вы победили."<<std::endl;
        if(user.hand.isBlackjack()){
            std::cout<<"К тому же, у вас туз и десятиочковая карта одной масти. Ваш выигрыш удвоен.. Вы выиграли "<<bet*2<<"."<<std::endl;
        }else{
            std::cout<<"Вы получили "<<bet<<"."<<std::endl;
        }
    } else if(dealerScore == 21){
        std::cout<<"У дилера 21. Вы проиграли. Вы потеряли "<<bet<<"."<<std::endl;
        userLost = true;
    }else{
        std::cout<<"Ни у кого не выпало 21, но ";
        if(userScore<21 && userScore>dealerScore){
            std::cout<<"вы ближе к 21, и поэтому выиграли. Ваш выигрыш "<<bet<<"."<<std::endl;

        }else{
            std::cout<<"дилер ближе к 21, и поэтому вы проиграли. Вы потеряли "<<bet<<"."<<std::endl;
            userLost = true;
        }
    }
    if(!userLost)
        user.totalCash=user.totalCash+bet*(!user.hand.isBlackjack()? 2: 4);
    std::cout <<"У вас "<<user.totalCash<<std::endl;
    user.hand.resetDeck();
    dealer.hand.resetDeck();
}

void Game::surrender() {
    user.totalCash += bet/2;
    bet /= 2;
}

size_t Game::getTotalCash() {
    return user.totalCash;
}


