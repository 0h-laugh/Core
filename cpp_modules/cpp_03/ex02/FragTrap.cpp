#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "FragTrap " << _name << " has no energy or is dead and cannot attack." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " powerfully attacks " << target
              << ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
