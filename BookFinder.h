//
// Created by Michael on 08.01.2021.
//

#ifndef CPP_LAB_FIVE_BOOKFINDER_H
#define CPP_LAB_FIVE_BOOKFINDER_H


#include <string>
#include "Book.h"

class BookFinder {
public:
    BookFinder(size_t _startYear, size_t _endYear);
    bool operator()(Book* b) const;

private:
    size_t startYear;
    size_t endYear;
};


#endif //CPP_LAB_FIVE_BOOKFINDER_H
