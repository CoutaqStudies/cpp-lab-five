//
// Created by Michael on 29.11.2020.
//

#ifndef CPP_LAB_FOUR_CARD_H
#define CPP_LAB_FOUR_CARD_H


#include <string>
#include <iostream>

class Card {
public:
    Card();
    Card(std::string _face);
    Card(const Card &c2);
    size_t getValue() const;
    std::string getFace() const;
    friend std::ostream& operator<<(std::ostream &out, const Card &card);

private:
    std::string face;
    size_t value = 99;
};


#endif //CPP_LAB_FOUR_CARD_H
