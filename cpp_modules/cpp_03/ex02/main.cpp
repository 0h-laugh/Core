#include "FragTrap.hpp"

int main() {
    FragTrap ft("Max");

    ft.attack("target dummy");
    ft.takeDamage(20);
    ft.beRepaired(10);
    ft.highFivesGuys();

    return 0;
}
