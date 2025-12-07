// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     return 0;
// }

#include <iostream>

class Base {
public:
    virtual void greet() const {
        std::cout << "Hello from Base!" << std::endl;
    }
};

class Derived : public Base {
public:
    void greet() const override { // override is optional but good practice
        std::cout << "Hello from Derived!" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->greet(); // Output: Hello from Derived!
    delete obj;
    return 0;
}