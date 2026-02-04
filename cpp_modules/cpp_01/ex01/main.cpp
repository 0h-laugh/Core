#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void) {
	int N = 5;
	Zombie *horde = zombieHorde(N, "Zombo");

	if (!horde)
		return 1;

	for (int i = 0; i < N; i++) {
		std::cout << "Zombie " << i + 1 << " ";
		horde[i].announce();
	}

	delete [] horde;

	return 0;
}
