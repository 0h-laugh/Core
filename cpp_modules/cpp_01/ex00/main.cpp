#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie* heapZombie = newZombie("Zombiesław");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Colesław");

    return 0;
}
