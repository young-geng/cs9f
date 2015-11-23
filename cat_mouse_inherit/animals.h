#ifndef ANIMALS_H
#define ANIMALS_H

#include "park.h"
#include "positions.h"

class Mouse : public Animal {
    using Animal::myPos;
    using Animal::myTarget;
 public:
    Mouse(std::string s, Position p) : Animal(s, p) {};
    bool Chase() override;
};
class Cat : public Animal {
    using Animal::myPos;
    using Animal::myTarget;
 public:
    Cat(std::string s, Position p) : Animal(s, p) {};
    bool Chase() override;
};
class Person : public Animal {
    using Animal::myPos;
    using Animal::myTarget;
 public:
    Person(std::string s, Position p) : Animal(s, p) {};
    bool Chase() override;
};




#endif