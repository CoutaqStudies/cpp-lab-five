//
// Created by Michael on 08.01.2021.
//

#ifndef CPP_LAB_FIVE_BOOK_H
#define CPP_LAB_FIVE_BOOK_H
#include <string>

class Book {
public:
    Book();
    Book(std::string _title, std::string _author, size_t _year);
    std::string getAuthor();
    std::string getTitle();
    size_t getYear();

private:
    std::string title;
    std::string author;
    size_t year;
};


#endif //CPP_LAB_FIVE_BOOK_H
