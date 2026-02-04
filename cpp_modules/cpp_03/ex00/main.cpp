#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("Bob");

    robot.attack("target");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("enemy");      
    robot.beRepaired(5);        

    return 0;
}
