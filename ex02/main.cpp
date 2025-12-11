#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\ntesting Animal cat dog wrong\n\n";
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();
	delete j; delete i; //delete meta;

	const Animal *animal[10];
	for (size_t i = 0; i < 5; i++)
		animal[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		animal[i] = new Cat();
	for (size_t i = 0; i < 10; i++)
	{
		animal[i]->makeSound();
	}
	for (size_t i = 0; i < 10; i++)
		delete animal[i];

	Cat *cat1 = new Cat;
	cat1->getBrain()->setIdea(0, "i am cat");
	cat1->getBrain()->setIdea(1, "i love jerry");
	Cat cat2(*cat1);
	delete cat1;
	std::cout << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << cat2.getBrain()->getIdea(1) << std::endl;
	std::cout << cat2.getBrain()->getIdea(200) << std::endl;

	return 0;
}
