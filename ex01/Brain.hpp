#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    // Orthodox Canonical Form
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    // Utility functions for testing
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif