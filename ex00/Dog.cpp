#include "Dog.hpp"

Dog::Dog(): Animal(){
	type = "Dog";
	std::cout << "(Dog) the default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other){}

Dog&	Dog::operator=(const Dog& other){
	type = other.type;
	return *this;
}

Dog::~Dog(){
	std::cout << "(Dog) the destructor called" << std::endl;
}

void	Dog::makeSound() const{
	std::cout << "bark bark !!" << std::endl;
}