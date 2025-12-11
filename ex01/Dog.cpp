#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "🐕 Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();  // Allocate Brain on heap
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "🐕 Dog copy constructor called" << std::endl;
    // DEEP COPY: create a NEW Brain and copy content
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "🐕 Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);  // Call base class assignment
        
        // Delete old brain
        delete this->brain;
        
        // DEEP COPY: create a NEW Brain and copy content
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "🐕 Dog destructor called" << std::endl;
    delete this->brain;  // Must delete Brain to avoid memory leak! 
}

void Dog::makeSound() const {
    std::cout << "🐕 Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}