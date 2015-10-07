#include <iostream>
#include <cmath>
#include "positions.h"

using namespace std;


bool verbose = true;

// You define the GetPositions function.
// It should read legal cat and mouse positions from the user
// and return the position values in its two arguments.
void GetPositions (Position& cat, Position& mouse) {
    float cat_r, cat_a, mouse_a;
    if (verbose)
        cout << "Cat radius: ";
    cin >> cat_r;

    if (verbose)
        cout << "Cat angle: ";
    cin >> cat_a;

    if (verbose)
        cout << "Mouse angle: ";
    cin >> mouse_a;
    cat.SetAbsolutePosition(cat_r, cat_a * M_PI / 180);
    mouse.SetAbsolutePosition(1.0, mouse_a * M_PI / 180);
}

// You define the RunChase function.
// Given initialized cat and mouse positions,
// it should simulate the cat chasing the mouse, printing the 
// result of each movement of cat and mouse.  Either the cat will 
// catch the mouse, or 30 time units will go by and the cat will 
// give up.
void RunChase (Position &cat, Position &mouse) {
    if (verbose) {
        cout << endl << "Cat:  ";
        cat.Print();
        cout << "Mouse:  ";
        mouse.Print();
        cout << endl;
    }
    for (int i = 1; i <= 30; i++) {
        Position original_cat = cat;
        if (cat.Sees(mouse)) {
            cat.IncrementPosition(-1, 0);
        } else {
            cat.IncrementPosition(0, 1.25);
        }
        
        if (verbose) {
            cout << "Time:  " << i << endl;
            cout << "Cat:  ";
            cat.Print();
            cout << "Mouse:  ";
            mouse.Print();
            cout << endl;
        }

        if (cat.IsAtStatue() && mouse.IsBetween(original_cat, cat)) {
            cout << "The cat caught the mouse at step " << i << endl;
            return;
        }
        mouse.IncrementPosition(0, 1);
    }
    cout << "The mouse escaped" << endl;
}

int main (int argc, char *argv[]) {
    if (argc == 2 && string("-q").compare(argv[1]) == 0) {
        verbose = false;
    }
    Position cat, mouse;
    GetPositions (cat, mouse);
    RunChase (cat, mouse);
    return 0;
}
