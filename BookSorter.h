//
// Created by Michael on 08.01.2021.
//

#ifndef CPP_LAB_FIVE_BOOKSORTER_H
#define CPP_LAB_FIVE_BOOKSORTER_H


#include "Book.h"
#define AUTHOR (0)
#define TITLE (1)
class BookSorter {
public:
    BookSorter();
    BookSorter(size_t sortBy);
    bool operator()(Book* b1, Book* b2) const;

private:
    size_t sortBy;
};


#endif //CPP_LAB_FIVE_BOOKSORTER_H
