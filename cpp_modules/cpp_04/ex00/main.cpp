#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " says: ";
    j->makeSound(); 

    std::cout << i->getType() << " says: ";
    i->makeSound(); 

    std::cout << meta->getType() << " says: ";
    meta->makeSound(); 

    delete meta;
    delete j;
    delete i;

    return 0;
}
