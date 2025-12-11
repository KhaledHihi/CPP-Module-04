#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	type = "WrongAnimal";
	std::cout << "(WrongAnimal) the default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	type = other.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other){
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "(WrongAnimal) the destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound !!" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return type;
}

