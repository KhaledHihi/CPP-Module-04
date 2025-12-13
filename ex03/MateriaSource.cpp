#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (size_t i = 0; i < 4; i++)
		tabl[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (other.tabl[i])
				this->tabl[i] = other.tabl[i]->clone();
			else
				this->tabl[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (other.tabl[i])
			{
				if (this->tabl[i])
					delete this->tabl[i];
				this->tabl[i] = other.tabl[i]->clone();
			}
			else
				this->tabl[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (size_t i = 0; i < 4; i++)
	{
		if (tabl[i])
			delete tabl[i];
	}
}

void MateriaSource::learnMateria(AMateria* m){
	for (size_t i = 0; i < 4; i++)
	{
		if (!tabl[i])
		{
			tabl[i] = m->clone();
			delete m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (size_t i = 0; i < 4; i++)
	{
		if (tabl[i] && tabl[i]->getType() == type)
			return tabl[i]->clone();
	}
	return NULL;
}
