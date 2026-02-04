#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap rob("Serena");

    rob.attack("target dummy");
    rob.takeDamage(30);
    rob.beRepaired(20);
    rob.guardGate();

    return 0;
}
