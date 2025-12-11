#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "🐈 Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();  // Allocate Brain on heap
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "🐈 Cat copy constructor called" << std::endl;
    // DEEP COPY: create a NEW Brain and copy content
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "🐈 Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);  // Call base class assignment
        
        // Delete old brain
        delete this->brain;
        
        // DEEP COPY: create a NEW Brain and copy content
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "🐈 Cat destructor called" << std::endl;
    delete this->brain;  // Must delete Brain to avoid memory leak!
}

void Cat::makeSound() const {
    std::cout << "🐈 Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}