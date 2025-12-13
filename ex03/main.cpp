#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void separator(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void subjectTest() {
    separator("Subject Test");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

void testFullInventory() {
    separator("Test:  Full Inventory");
    
    Character* hero = new Character("Hero");
    
    std::cout << "Equipping 5 materias (max is 4):\n" << std::endl;
    hero->equip(new Ice());
    hero->equip(new Cure());
    hero->equip(new Ice());
    hero->equip(new Cure());
    hero->equip(new Ice());  // Should be ignored
    
    ICharacter* enemy = new Character("Enemy");
    
    std::cout << "Using all slots:" << std::endl;
    hero->use(0, *enemy);
    hero->use(1, *enemy);
    hero->use(2, *enemy);
    hero->use(3, *enemy);
    hero->use(4, *enemy);  // Invalid index
    
    delete enemy;
    delete hero;
}

void testUnequip() {
    separator("Test: Unequip Memory Management");
    
    Character* mage = new Character("Mage");
    ICharacter* target = new Character("Target");
    
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    mage->equip(ice);
    mage->equip(cure);
    
    std::cout << "Before unequip:" << std::endl;
    mage->use(0, *target);
    mage->use(1, *target);
    
    std::cout << "\nUnequipping slot 0:" << std::endl;
    AMateria* floor = ice;  // Save address
    mage->unequip(0);
    
    std::cout << "After unequip:" << std::endl;
    mage->use(0, *target);  // Should do nothing
    mage->use(1, *target);  // Should work
    
    std::cout << "\nDeleting unequipped materia:" << std:: endl;
    delete floor;
    
    delete target;
    delete mage;
}

void testDeepCopy() {
    separator("Test: Deep Copy");
    
    Character* char1 = new Character("Char1");
    char1->equip(new Ice());
    char1->equip(new Cure());
    
    Character* char2 = new Character(*char1);
    
    ICharacter* dummy = new Character("Dummy");
    
    std::cout << "char1 using materias:" << std::endl;
    char1->use(0, *dummy);
    char1->use(1, *dummy);
    
    std::cout << "\nchar2 using materias:" << std::endl;
    char2->use(0, *dummy);
    char2->use(1, *dummy);
    
    std::cout << "\nDeleting char1:" << std::endl;
    delete char1;
    
    std::cout << "char2 still works:" << std::endl;
    char2->use(0, *dummy);
    char2->use(1, *dummy);
    
    delete dummy;
    delete char2;
}

void testLearnMateria() {
    separator("Test: Learn Materia");
    
    MateriaSource* src = new MateriaSource();
    
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    src->learnMateria(ice);
    src->learnMateria(cure);
    
    // Safe to delete because learnMateria clones
    delete ice;
    delete cure;
    
    AMateria* created1 = src->createMateria("ice");
    AMateria* created2 = src->createMateria("cure");
    AMateria* created3 = src->createMateria("fire");  // Unknown
    
    if (created1) {
        std::cout << "✅ Created:  " << created1->getType() << std::endl;
        delete created1;
    }
    if (created2) {
        std::cout << "✅ Created: " << created2->getType() << std::endl;
        delete created2;
    }
    if (! created3) {
        std::cout << "✅ Unknown type returns NULL" << std::endl;
    }
    
    delete src;
}

int main() {
    subjectTest();
    testFullInventory();
    testUnequip();
    testDeepCopy();
    testLearnMateria();
    
    separator("🎉 All Tests Completed!");
    std::cout << "Run with valgrind to check memory.\n" << std::endl;
    
    return 0;
}