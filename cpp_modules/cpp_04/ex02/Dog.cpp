#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    std::cout << "Dog constructor called\n";
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other) {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
    std::cout << "Dog says: Woof woof!\n";
}

Brain* Dog::getBrain() const {
    return brain;
}
