#include <iostream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "positions.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::ostream;

void Position::Normalize() {
    myRadius = max<float>(myRadius, 1.0);
    myAngleInRadians = NormalizeAngle(myAngleInRadians);
}

float Position::NormalizeAngle(float angle) {
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0) {
        angle += 2 * M_PI;
    }
    return angle;
}

Position::Position() {
    myRadius = 1;
    myAngleInRadians = 0;
}

Position::Position(float r) {
    myRadius = r;
    myAngleInRadians = 0;

}

Position::Position(float r, float thetaInRadians) {
    myRadius = r;
    myAngleInRadians = thetaInRadians;
    Normalize();
}


void Position::SetAbsolutePosition (float r, float thetaInRadians) {
    myRadius = r;
    myAngleInRadians = thetaInRadians;
    Normalize();
}

void Position::IncrementPosition (float rChange, float thetaChange) {
    myAngleInRadians += thetaChange;
    myRadius += rChange;
    Normalize();
}

void Position::IncrementPosition2 (float rChange, float angularDistChange) {
    myAngleInRadians += angularDistChange / myRadius;
    myRadius += rChange;
    Normalize();
}

void Position::Print() {
    cout << "Radius:  " << myRadius << ",   Angle:  " << myAngleInRadians << endl;
}

bool Position::Sees(Position pos) {
    return myRadius * cos(myAngleInRadians - pos.myAngleInRadians) >= 1.0;
}

bool Position::IsAtStatue() {
    return myRadius == 1.0;
}

bool Position::IsBetween(Position pos1, Position pos2) {
    float A = pos2.myAngleInRadians, B = myAngleInRadians, C = pos1.myAngleInRadians;
    return cos(B - A) > cos(C - A) && cos(C - B) > cos(C - A);
}

bool Position::operator== (Position coords) {
    return coords.myRadius == myRadius && coords.myAngleInRadians == myAngleInRadians;
}


ostream& operator<< (ostream &out, Position &pos) {
    return out << "Radius: " << pos.myRadius << ", Angle: " << pos.myAngleInRadians;
}