//
// Created by Anastasija Fedorenko on 2025-04-21.
//

#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using namespace std;
class Human {
protected:
    string name;
    string surname;

public:
    Human();
    Human(string name, string surname);
    virtual ~Human() {
        name.clear();
        surname.clear();
    }

    string getName()const{return name;}
    string getSurname()const{return surname;}
    const void setName(const string name){this->name = name;}
    const void setSurname(const string surname){this->surname = surname;}
};

#endif