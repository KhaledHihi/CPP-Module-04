#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(const AMateria& other){
	type = other.type;
}

AMateria&	AMateria::operator=(const AMateria& other){
	type = other.type;
	return *this;
}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

void AMateria::use(ICharacter& target){
	std::cout << "Default attack (no type) on " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const{
	return type;
}

