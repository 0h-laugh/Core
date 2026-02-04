#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Max");

    dt.attack("dummy");
    dt.takeDamage(20);
    dt.beRepaired(10);
    dt.guardGate();       
    dt.highFivesGuys();   
    dt.whoAmI();

    return 0;
}
