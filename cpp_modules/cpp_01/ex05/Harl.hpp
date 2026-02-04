#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
public:
    Harl();
    void complain(std::string level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef void (Harl::*HarlMemFn)(void);
    HarlMemFn funcs[4];
    std::string levels[4];
};

#endif
