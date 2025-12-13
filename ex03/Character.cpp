#include "Character.hpp"

Character::Character(){
	name = "default";
	keep = new t_unequip;
	keep->a = NULL;
	keep->next = NULL;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other){
	name = other.name;
	if (this != &other)
	{
		keep = new t_unequip;
		keep->a = NULL;
		keep->next = NULL;
		for (size_t i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
}

Character&	Character::operator=(const Character& other){
	name = other.name;
	if (this != &other)
	{
		if (keep->a)
			delete keep->a;
		delete keep;
		keep = new t_unequip;
		keep->a = NULL;
		keep->next = NULL;
		for (size_t i = 0; i < 4; i++)
		{
			if (other.inventory[i])
			{
				if (this->inventory[i])
					delete this->inventory[i];
				this->inventory[i] = other.inventory[i]->clone();
			}
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(){
	t_unequip* temp;

	temp = keep;
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	while (temp)
	{
		delete temp->a;
		temp = temp->next;
	}
	temp = keep;
	while (temp)
	{
		temp = temp->next;
		delete keep;
		keep = temp;
	}
}

Character::Character(const std::string name){
	this->name = name;
	keep = new t_unequip;
	keep->a = NULL;
	keep->next = NULL;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
}

std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m){
	for (size_t i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx){
	t_unequip* temp = NULL;

	temp = keep;
	if (idx >= 0 && idx < 4)
	{
		if (!temp->a)
			temp->a = inventory[idx];
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new t_unequip;
			temp = temp->next;
			temp->a = inventory[idx];
			temp->next = NULL;
		}
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (inventory[idx])
		inventory[idx]->use(target);
}
