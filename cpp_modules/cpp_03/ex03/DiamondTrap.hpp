#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;  

public:
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    using ScavTrap::attack; 

    void whoAmI();
};

#endif
