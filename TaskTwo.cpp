//
// Created by Michael on 08.01.2021.
//
#include <map>
#include <fstream>
#include <iostream>

const char* dividers = ".,:!;? ";
const size_t MAXLEN = 1000;
const std::string fileText = "text.txt";
const size_t MINLETTERS = 3;
const size_t MINOCCURANCES = 7;

void TaskTwo(){
    std::map<std::string, int> map;
    std::ifstream file(fileText);
    if (file.is_open())
    {
        while (file.peek()!=EOF)
        {
            char text[MAXLEN];
            file.getline(text, MAXLEN);
            char* substr = std::strtok(text, dividers);
            while (substr != nullptr)
            {
                std::string word = substr;
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                auto mapIterator = map.find(word);
                if (mapIterator == map.end()) map.insert(std::make_pair(word, 1));
                else map[word]++;
                substr = std::strtok(nullptr, dividers);
            }
        }
    }
    file.close();
    auto mapIterator = map.begin();
    std::multimap<int, std::string, std::greater<>> sorted_map;

    for (int i = 0; mapIterator != map.end(); mapIterator++, i++)
        if (mapIterator->first.length() > MINLETTERS && mapIterator->second >= MINOCCURANCES)
            sorted_map.insert(std::make_pair(mapIterator->second, mapIterator->first));

    for (auto const& entry : sorted_map)
    {
        std::cout<< entry.second << " " << entry.first << std::endl;
    }
}
