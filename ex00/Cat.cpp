#include "Cat.hpp"

Cat::Cat(): Animal(){
	type = "Cat";
	std::cout << "(Cat) the default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){}

Cat&	Cat::operator=(const Cat& other){
	type = other.type;
	return *this;
}

Cat::~Cat(){
	std::cout << "(Cat) the destructor called" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "meow meow !!" << std::endl;
}
