//
// Created by Michael on 08.01.2021.
//
#include <iostream>
#include "Templates.h"
void TaskOne(){
    DataManager dmInt = DataManager<int>();
    dmInt.push(1);
    dmInt.push(2);
    dmInt.push(3);
    dmInt.push(4);
    dmInt.pop();
    std::ostream_iterator<int> out_int (std::cout,"\n");
    dmInt.iterate(out_int);

    DataManager dmDouble = DataManager<double>();
    double doubleArr[] = {1.2, 2.4, 6.4};

    dmDouble.push(doubleArr, 3);
    std::ostream_iterator<double> out_double (std::cout,"\n");
    dmDouble.iterate(out_double);

    DataManager dmChar = DataManager<char>();
    char charArr[] = {'h', 'i'};

    dmChar.push(charArr, 2);
    std::ostream_iterator<char> out_char (std::cout,"");
    dmChar.iterate(out_char);
}
