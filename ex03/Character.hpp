#pragma once

#include "ICharacter.hpp"

typedef struct l_unequip
{
	AMateria* a;
	struct l_unequip* next;
} t_unequip;

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		t_unequip* keep;
	public:
		Character();
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		Character(const std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
