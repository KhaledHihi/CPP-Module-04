#pragma once

#include <iostream>
#include "Character.hpp"

class	ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};