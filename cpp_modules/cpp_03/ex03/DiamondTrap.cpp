#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name) {
    _hitPoints = FragTrap::_hitPoints;       
    _energyPoints = ScavTrap::_energyPoints; 
    _attackDamage = FragTrap::_attackDamage; 

    std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name
              << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
