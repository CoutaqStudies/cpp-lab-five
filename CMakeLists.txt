cmake_minimum_required(VERSION 3.17)
project(cpp_lab_five)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_lab_five main.cpp Templates.h Book.cpp Book.h BookFinder.cpp BookFinder.h BookSorter.cpp BookSorter.h "TaskSix/Source Files/Game.cpp" "TaskSix/Header Files/Game.h" "TaskSix/Source Files/Player.cpp" "TaskSix/Header Files/Player.h" "TaskSix/Source Files/Dealer.cpp" "TaskSix/Header Files/Dealer.h" "TaskSix/Source Files/Card.cpp" "TaskSix/Header Files/Card.h" "TaskSix/Source Files/Deck.cpp" "TaskSix/Header Files/Deck.h" "TaskSix/Source Files/Hand.cpp" "TaskSix/Header Files/Hand.h" "TaskSix/Source Files/IFormattable.cpp" "TaskSix/Header Files/IFormattable.h" "TaskSix/Source Files/IDontknow.cpp" "TaskSix/Header Files/IDontknow.h")