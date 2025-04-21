//
// Created by Anastasija Fedorenko on 2025-04-21.
//

#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human {
protected:
    std::string name;
    std::string surname;

public:
    Human(std::string name, std::string surname);
    virtual void printInfo() const = 0;
    virtual ~Human() {}
};

#endif