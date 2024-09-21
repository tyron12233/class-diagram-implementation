#pragma once
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

inline void clearScreen() {
    std::system(CLEAR);
}

inline void pauseScreen() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}
