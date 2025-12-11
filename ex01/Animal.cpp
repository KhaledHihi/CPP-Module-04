#include "Animal.hpp"

Animal::Animal(){
	type = "Animal";
	std::cout << "(Animal) the default constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	type = other.type;
}

Animal&	Animal::operator=(const Animal& other){
	type = other.type;
	return *this;
}

Animal::~Animal(){
	std::cout << "(Animal) the destructor called" << std::endl;
}

void	Animal::makeSound() const{
	std::cout << "Animal sound !!" << std::endl;
}

std::string	Animal::getType() const{
	return type;
}