#ifndef PARK_H
#define PARK_H
#include <vector>
#include <string>
#include <memory>
#include "positions.h"
class Animal {
friend class Scene;
public:
	Animal (std::string s, Position p);
	std::string Name () const;
	Position Pos () const;
	// Move the animal, and return true if it catches 
	// its target.
	virtual bool Chase () = 0;
protected:
	std::string myName;	// animal's name
	Position myPos;	// animal's position
	Animal *myTarget;	// ptr to animal being chased; 0 if none
};
class Scene {
public:
	Scene ();
	int Length ();
	Animal* &operator[] (int k);
private:
	std::vector<Animal*> allAnimals;
};

#endif
