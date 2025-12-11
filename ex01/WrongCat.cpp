#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	type = "WrongCat";
	std::cout << "(WrongCat) the default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){}

WrongCat&	WrongCat::operator=(const WrongCat& other){
	type = other.type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "(WrongCat) the destructor called" << std::endl;
}

void	WrongCat::makeSound() const{
	std::cout << "ha ha ha !!" << std::endl;
}
