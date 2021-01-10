//
// Created by Michael on 08.01.2021.
//

#include "BookFinder.h"

BookFinder::BookFinder(size_t _startYear, size_t _endYear) {
    startYear = _startYear;
    endYear = _endYear;
}

bool BookFinder::operator()(Book *b) const {
    return b->getYear() >= startYear && b->getYear() <= endYear;
}
