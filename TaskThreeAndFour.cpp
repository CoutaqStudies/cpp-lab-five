//
// Created by Michael on 08.01.2021.
//
#include "Book.h"
#include <clocale>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "BookSorter.h"
#include "BookFinder.h"

void TaskThree(){
    std::vector<Book*> books;
    books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
    books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
    books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
    books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
    books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
    books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
    books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
    books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
    books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));
    std::cout << "\nКниги в алфавитном порядке:\n\n";
    BookSorter book_sorter;
    std::sort(books.begin(), books.end(), book_sorter);
    std::vector<Book*>::iterator i;
    for (i = books.begin(); i != books.end(); ++i)
    {
        std::cout << (*i)->getAuthor() << " \""
                  << (*i)->getTitle() << "\"" << std::endl;
    }
    BookFinder book_finder(2005, 2014);
    auto finder = std::find_if(books.begin(), books.end(), book_finder);
    std::cout << "\nКниги в диапазоне года издания 2005 - 2014:\n\n";
    while (finder != books.end())
    {
        std::cout << (*finder)->getAuthor() << " \""
                 << (*finder)->getTitle() << "\"" << std::endl;
        finder = std::find_if(++finder, books.end(), book_finder);
    }
    for (i = books.begin(); i != books.end(); ++i)
    {
        delete (*i);
    }

    std::vector<int> years;
    for (auto& i : books)
        years.push_back(i->getYear());

    std::cout <<"Task Four: Книги новее 2009 года: "<< std::count_if(years.begin(), years.end(), std::bind(std::greater<>(),std::placeholders::_1,  2009)) << std::endl; //bind2nd удалили в c++ 20, а если я ставлю c++ 14 то другое не работает, проще это на bind заменить
}