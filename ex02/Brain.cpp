#include "Brain.hpp"

Brain::Brain() {
    std::cout << "🧠 Brain default constructor called" << std::endl;
    // Ideas are empty by default
}

Brain::Brain(const Brain& other) {
    std::cout << "🧠 Brain copy constructor called" << std::endl;
    // DEEP COPY: copy all 100 ideas
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other. ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "🧠 Brain assignment operator called" << std::endl;
    if (this != &other) {
        // DEEP COPY: copy all 100 ideas
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other. ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "🧠 Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "";
}