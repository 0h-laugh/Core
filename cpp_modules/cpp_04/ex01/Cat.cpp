#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    std::cout << "Cat constructor called\n";
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other) {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const {
    std::cout << "Cat says: Meow!\n";
}

Brain* Cat::getBrain() const {
    return brain;
}
