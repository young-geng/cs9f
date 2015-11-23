#include "animals.h"
#include "positions.h"


using namespace std;


bool Mouse::Chase() {
    myPos.IncrementPosition2(0, 1);
    return false;
}

bool Cat::Chase() {
    Position old = myPos;
    if (!myPos.Sees(myTarget->Pos())) {
        myPos.IncrementPosition2(0, 1.25);
    } else {
        myPos.IncrementPosition2(-1, 0);
    }
    return myTarget->Pos().IsBetween(old, myPos);
}

bool Person::Chase() {
    if (!myPos.Sees(myTarget->Pos())) {
        myPos.IncrementPosition2(0, -2);
    }
    return false;
}