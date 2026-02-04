#include "Harl.hpp"

Harl::Harl() {
    funcs[0] = &Harl::debug;
    funcs[1] = &Harl::info;
    funcs[2] = &Harl::warning;
    funcs[3] = &Harl::error;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevelIndex(std::string level) {
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;
    }
    return -1; 
}

void Harl::complain(std::string level) {
    int levelIndex = getLevelIndex(level);

    switch (levelIndex) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            (this->*funcs[0])();
            [[fallthrough]];
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            (this->*funcs[1])();
            [[fallthrough]];
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            (this->*funcs[2])();
            [[fallthrough]];
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            (this->*funcs[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
